import itertools
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
flags.DEFINE_string(
    'union_addresses', None,
    'comma-separated list of address offsets to union together, hex')
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
    self.file.write('// clang-format on\n')
    self.file.close()

  @property
  def whitespace(self):
    return " " * self.tabs

  def write(self, msg=''):
    if self.file is None:
      self.file = open(self.path, 'w')
      self.file.write('// clang-format off\n\n')
    if len(msg):
      self.file.write(f'{self.whitespace}{msg}\n')
    else:
      self.file.write('\n')

  def comment(self, content, clean=True):
    if clean:
      content = re.sub(' +', ' ', content)
    content = textwrap.fill(
        content,
        width=80,
        initial_indent='// ',
        subsequent_indent=self.whitespace + '// ',
    )
    self.write(content)

  def newln(self):
    self.write()


class Biffile:

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

  def __init__(self, formatter):
    self.fmt = formatter
    self.current_address = 0
    self.num_reserved = 0
    self.union_addresses = [
        int(x, base=16) for x in FLAGS.union_addresses.split(',')
    ]
    self.in_union = False

  @property
  def section(self):
    return self.fmt

  def write_peripheral(self, peripheral):
    sorted_registers = sorted(
        peripheral.registers, key=lambda x: x.address_offset)
    blocks = itertools.groupby(sorted_registers, lambda x: x.address_offset)

    for address, registers in blocks:
      self.write_reserved_register(address)
      self.write_union_start(address)
      self.write_registers(registers)
      self.write_union_end(address)

  def write_reserved_register(self, address):
    if self.current_address == 0 or self.current_address == address:
      return
    reserved_size = (address - current_address) // 4
    self.fmt.write(
        f'ETL_BFF_REG_RESERVED(uint32_t, reserved{self.num_reserved+1}, {reserved_size//4})'
    )
    self.fmt.newln()
    self.num_reserved += 1

  def write_union_start(self, address):
    if address not in self.union_addresses or self.in_union:
      return
    self.fmt.write('union {')
    self.in_union = True

  def write_union_end(self, address):
    if not self.in_union:
      return
    self.fmt.write('}  // union')
    self.fmt.newln()
    self.in_union = False

  def write_registers(self, registers):
    for register in registers:
      if FLAGS.register_descriptions:
        self.register_description(register)
      self.register_begin(register)
      with self.section:
        self.register_fields(register.fields)
      self.register_end(register)
    if not self.in_union:
      self.fmt.newln()

  def register_description(self, register):
    self.fmt.write(f'// {register.name}')
    self.fmt.write(f'//')
    description = re.sub(' +', ' ', register.description)
    description = textwrap.fill(
        description, width=80, initial_indent='// ', subsequent_indent='// ')
    self.fmt.write(description)
    self.fmt.write('//')
    self.fmt.write(f'//   Offset: 0x{register.address_offset:03X}')
    if register._reset_value:
      self.fmt.write(f'//   Reset value: 0x{register._reset_value:08X}')

  def register_begin(self, register):
    size = self.size_map[register._size]
    reg_type = self.reg_type[register._access]
    self.fmt.write(f'{reg_type}({size}, {register.name},')

  def register_end(self, register):
    self.fmt.write(')')

  def register_fields(self, fields):
    current_bit = 31
    fields = sorted(fields, key=lambda x: x.bit_offset, reverse=True)

    for f in fields:
      lsb = f.bit_offset
      msb = lsb + f.bit_width - 1

      if msb != current_bit:
        self.reserved_bits(current_bit, msb)
      self.field(f)
      current_bit = lsb - 1
    if current_bit >= 0:
      self.reserved_bits(current_bit, -1)

  def reserved_bits(self, current_bit, msb):
    if not FLAGS.reserved_comments:
      self.fmt.newln()
      return

    gap = current_bit - msb
    if gap == 1:
      reserved_str = f'// {current_bit} reserved'
    else:
      reserved_str = f'// {current_bit}:{msb+1} reserved'
    self.fmt.write(reserved_str)

  def field(self, field):
    if not FLAGS.field_descriptions:
      return
    self.fmt.comment(field.description)
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
        self.write_enumerated_values(field)
      self.fmt.write(f')')

  def write_enumerated_values(self, field):
    for v in field.enumerated_values:
      bit_str = f'{v.value:b}'
      if len(bit_str) < field.bit_width:
        bit_str = '0' * (field.bit_width - len(bit_str)) + bit_str
      self.fmt.write(f'ETL_BFF_ENUM(0b{bit_str}, {v.name})')


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


if __name__ == '__main__':
  app.run(main)