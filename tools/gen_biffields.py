import re
import textwrap

from absl import app
from absl import flags
from absl import logging
from cmsis_svd.parser import SVDParser

from bazel_tools.tools.python.runfiles import runfiles

flags.DEFINE_string('svd_path',
                    '//pino/third_party/stm32cubeg4/STM32G474xx.svd',
                    'Path to svd, either //workspace/and/path, or absolute')
flags.DEFINE_string('output_path', None, 'Path to write biffields.')
flags.DEFINE_bool('register_descriptions', True,
                  'Whether to add register descriptions')
flags.DEFINE_bool('field_descriptions', True,
                  'Whether to add field descriptions')
flags.DEFINE_bool('reserved_comments', True,
                  'Whether to add bitfield reserved comments')

flags.mark_flags_as_required(['output_path'])

FLAGS = flags.FLAGS


class Formatter:

  def __init__(self, path):
    self.tabs = 0
    self.path = path
    self.file = None

  def __enter__(self):
    self.tabs += 2

  def __exit__(self, *args):
    self.tabs -= 2
    if self.tabs < 0:
      file.write('// clang-format on')
      self.file.close()

  def write(self, msg=''):
    if self.file is None:
      self.file = open(self.path, 'w')
      self.file.write('// clang-format off')
    if len(msg):
      self.file.write(f'{" " * self.tabs}{msg}\n')
    else:
      self.file.write('\n')

  def newln(self):
    self.write()


class BiffieldBase:

  def __init__(self, formatter):
    self.fmt = formatter

  @property
  def section(self):
    return self.fmt


class BiffieldRegister(BiffieldBase):
  size_map = {
      32: 'uint32_t',
      16: 'uint16_t',
      8: 'uint8_t',
  }

  reg_type = {
      None: 'ETL_BFF_REG_RW',
      'read-write': 'ETL_BFF_REG_RW',
      'read-only': 'ETL_BFF_REG_RO',
      'write-only': 'ETL_BFF_REG_WO',
  }

  def __init__(self, descriptions, reserved_comments, *args, **kwargs):
    super(BiffieldRegister, self).__init__(*args, **kwargs)
    self.description = descriptions
    self.reserved_comments = reserved_comments

  def _write_description(self, register):
    if not self.description:
      return
    description = re.sub(' +', ' ', register.description)
    description = textwrap.fill(
        description, width=80, initial_indent='// ', subsequent_indent='// ')
    self.fmt.write(description)

  def write(self, register):
    self._write_description(register)

    size = self.size_map[register._size]
    reg_type = self.reg_type[register._access]
    self.fmt.write(f'{reg_type}({size}, {register.name},')
    with self.section:
      last_bit = None
      for idx, f in enumerate(
          sorted(register.fields, key=lambda x: x.bit_offset, reverse=True)):
        if last_bit is not None:
          high_bit = (f.bit_offset + f.bit_width - 1)
          gap = last_bit - high_bit - 1
          if gap > 0:
            if self.reserved_comments:
              if gap == 1:
                reserved_str = f'// {last_bit-1} reserved'
              else:
                reserved_str = f'// {last_bit-1} : {high_bit+1} reserved'
            else:
              reserved_str = ''
            self.fmt.write(reserved_str)
        # self.write_field(f)
        last_bit = f.bit_offset
    self.fmt.write(')')


class Biffile:

  def __init__(self, output_path, register_descriptions, reserved_comments):
    self.formatter = Formatter(output_path)
    self.regwriter = BiffieldRegister(register_descriptions, reserved_comments,
                                      self.formatter)

    # self.output_path = output_path
    self.num_reserved = 0
    self.reg_desc = register_descriptions
    self.reserved_comments = reserved_comments

  @property
  def section(self):
    return self.formatter

  def write_peripheral(self, peripheral):
    next_addr = 0
    for idx, r in enumerate(
        sorted(peripheral.registers, key=lambda x: x.address_offset)):
      if r.address_offset != next_addr:
        reserved_size = (r.address_offset - next_addr)
        self.write_reserved_register(reserved_size)
      self.write_register(r)
      self.formatter.newln()
      next_addr = r.address_offset + 4

  def write_reserved_register(self, reserved_size):
    self.formatter.write(
        f'ETL_BFF_REG_RESERVED(uint32_t, reserved{self.num_reserved+1}, {reserved_size//4})'
    )
    self.formatter.newln()
    self.num_reserved += 1

  def write_register(self, register):
    self.regwriter.write(register)

  def write_field(self, field):
    if field.bit_width == 1:
      dtype = 'bool'
    elif field.bit_width <= 8:
      dtype = 'uint8_t'
    elif field.bit_width <= 16:
      dtype = 'uint16_t'
    else:
      dtype = 'uint32_t'
    start = field.bit_offset
    end = field.bit_offset + field.bit_width - 1
    if not field.is_enumerated_type:
      self.formatter.write(
          f'ETL_BFF_FIELD({end}:{start}, {dtype}, {field.name})')
    else:
      self.formatter.write(
          f'ETL_BFF_FIELD_E({end}:{start}, {dtype}, {field.name},')
      with self.section:
        self.write_enumerated_values(field, field.enumerated_values)
      self.formatter.write(f')')

  def write_enumerated_values(self, field, values):
    for v in values:
      bit_str = f'{v.value:b}'
      if len(bit_str) < field.bit_width:
        bit_str = '0' * (field.bit_width - len(bit_str)) + bit_str
      self.formatter.write(f'ETL_BFF_ENUM(0b{bit_str}, {v.name})')


def main(unused_argv):
  del unused_argv

  r = runfiles.Create()
  svd_path = FLAGS.svd_path
  if svd_path.startswith('//'):
    svd_path = r.Rlocation(svd_path[2:])
  parser = SVDParser.for_xml_file(svd_path)
  fdcan1 = [
      p for p in parser.get_device().peripherals if p.name.lower() == 'fdcan1'
  ][0]
  # dest_file = open(FLAGS.output_path, 'w')

  Biffile(FLAGS.output_path, FLAGS.register_descriptions,
          FLAGS.reserved_comments).write_peripheral(fdcan1)

  # print('%s @ 0x%08x' % (fdcan1.name,fdcan1.base_address))
  # for r in fdcan1.registers:
  #   print('  %s @ 0x%08x %d' % (r.name,r.address_offset, r._size))
  #   for f in r.fields:
  #     print('    %s @ %d:%d %s' % (f.name,f.bit_offset, f.bit_width, f.access))
  #     if f.is_enumerated_type:
  #       print('\n\n\nYAS\n\n\n')

  # dest_file.close()


if __name__ == '__main__':
  app.run(main)