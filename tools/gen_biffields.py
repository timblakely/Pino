import re
import tempfile
import textwrap

from absl import app
from absl import flags
from absl import logging
from cmsis_svd.parser import SVDParser
import svdtools
import xml.etree.ElementTree as ET
import yaml

flags.DEFINE_string('svd_path', None,
                    'Path to svd, either //workspace/and/path, or absolute')
flags.DEFINE_string('peripheral', None, 'Peripheral to generate')
flags.DEFINE_string('output_path', None, 'Path to write biffields.')
flags.DEFINE_string('svd_yaml_patch', None,
                    'If set, will use svdtools to apply a yaml patch')
flags.DEFINE_bool('register_descriptions', True,
                  'Whether to add register descriptions')
flags.DEFINE_bool('register_offsets', True, 'Whether to add register offsets')
flags.DEFINE_bool('field_descriptions', True,
                  'Whether to add field descriptions')
flags.DEFINE_bool('reserved_comments', True,
                  'Whether to add bitfield reserved comments')

flags.mark_flags_as_required(['output_path', 'svd_path', 'peripheral'])

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

  def finish(self):
    self.file.write('\n// clang-format on\n')
    self.file.close()

  def write(self, msg=''):
    if self.file is None:
      self.file = open(self.path, 'w')
      self.file.write('// clang-format off\n\n')
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


class FieldWriter(BiffieldBase):

  def __init__(self, *args, **kwargs):
    super(FieldWriter, self).__init__(*args, **kwargs)

  def write(self, field):
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
      self.fmt.write(f'ETL_BFF_FIELD({end}:{start}, {dtype}, {field.name})')
    else:
      self.fmt.write(f'ETL_BFF_FIELD_E({end}:{start}, {dtype}, {field.name},')
      with self.section:
        self.write_enumerated_values(field, field.enumerated_values)
      self.fmt.write(f')')

  def write_enumerated_values(self, field, values):
    for v in values:
      bit_str = f'{v.value:b}'
      if len(bit_str) < field.bit_width:
        bit_str = '0' * (field.bit_width - len(bit_str)) + bit_str
      self.fmt.write(f'ETL_BFF_ENUM(0b{bit_str}, {v.name})')


class RegWriter(BiffieldBase):
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

  def __init__(self, *args, **kwargs):
    super(RegWriter, self).__init__(*args, **kwargs)
    self.fieldwriter = FieldWriter(self.fmt)

  def _write_description(self, register):
    if not FLAGS.register_descriptions:
      return
    self.fmt.write(f'// {register.name}')
    self.fmt.write(f'//')
    description = re.sub(' +', ' ', register.description)
    description = textwrap.fill(
        description, width=80, initial_indent='// ', subsequent_indent='// ')
    self.fmt.write(description)

  def _write_reserved(self, field):
    if self.last_bit is None:
      self.last_bit = field.bit_offset
      return

    high_bit = (field.bit_offset + field.bit_width - 1)
    gap = self.last_bit - high_bit - 1
    if gap > 0:
      if FLAGS.reserved_comments:
        if gap == 1:
          reserved_str = f'// {self.last_bit-1} reserved'
        else:
          reserved_str = f'// {self.last_bit-1} : {high_bit+1} reserved'
      else:
        reserved_str = ''
      self.fmt.write(reserved_str)
    self.last_bit = field.bit_offset

  def _write_offset(self, register):
    if not FLAGS.register_offsets:
      return
    self.fmt.write('//')
    self.fmt.write(f'//   Offset: 0x{register.address_offset:03X}')
    if register._reset_value:
      self.fmt.write(f'//   Reset value: 0x{register._reset_value:08X}')

  def write(self, register):
    self.last_bit = None
    self._write_description(register)
    self._write_offset(register)

    size = self.size_map[register._size]
    reg_type = self.reg_type[register._access]
    self.fmt.write(f'{reg_type}({size}, {register.name},')
    with self.section:
      for f in sorted(
          register.fields, key=lambda x: x.bit_offset, reverse=True):
        self._write_reserved(f)
        self.fieldwriter.write(f)
    self.fmt.write(')')


class Biffile:

  def __init__(self, formatter):
    self.fmt = formatter
    self.regwriter = RegWriter(self.fmt)

    # self.output_path = output_path
    self.num_reserved = 0

  @property
  def section(self):
    return self.fmt

  def write_peripheral(self, peripheral):
    next_addr = 0
    for idx, r in enumerate(
        sorted(peripheral.registers, key=lambda x: x.address_offset)):
      if r.address_offset != next_addr:
        reserved_size = (r.address_offset - next_addr)
        self.write_reserved_register(reserved_size)
      self.write_register(r)
      self.fmt.newln()
      next_addr = r.address_offset + 4

  def write_reserved_register(self, reserved_size):
    self.fmt.write(
        f'ETL_BFF_REG_RESERVED(uint32_t, reserved{self.num_reserved+1}, {reserved_size//4})'
    )
    self.fmt.newln()
    self.num_reserved += 1

  def write_register(self, register):
    self.regwriter.write(register)


def main(unused_argv):
  del unused_argv

  svd_path = FLAGS.svd_path
  if FLAGS.svd_yaml_patch:
    with open(FLAGS.svd_yaml_patch, "r") as f:
      root = yaml.safe_load(f)
      root["_path"] = FLAGS.svd_yaml_patch
    svd = ET.parse(FLAGS.svd_path)
    svdtools.patch.yaml_includes(root)
    svdtools.patch.process_device(svd, root)
    _, svd_path = tempfile.mkstemp()
    svd.write(svd_path)

  parser = SVDParser.for_xml_file(svd_path)
  peripheral = None
  for p in parser.get_device().peripherals:
    if p.name.lower() == FLAGS.peripheral.lower():
      peripheral = p
      break

  formatter = Formatter(FLAGS.output_path)
  Biffile(formatter).write_peripheral(peripheral)
  formatter.finish()

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