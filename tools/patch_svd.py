from absl import app
from absl import flags
from absl import logging
import svdtools
import xml.etree.ElementTree as ET
import yaml

flags.DEFINE_string("svd_path", None,
                    "Path to svd, either //workspace/and/path, or absolute")
flags.DEFINE_string("yaml_path", None,
                    "Path to yaml, either //workspace/and/path, or absolute")
flags.DEFINE_string("output_path", None, "Path to write patched svd.")

flags.mark_flags_as_required(["svd_path", "yaml_path", "output_path"])

FLAGS = flags.FLAGS


def main(unused_argv):
  del unused_argv
  with open(FLAGS.yaml_path, "r") as f:
    root = yaml.safe_load(f)
    root["_path"] = FLAGS.yaml_path
  svd = ET.parse(FLAGS.svd_path)
  svdtools.patch.yaml_includes(root)
  svdtools.patch.process_device(svd, root)
  svd.write(FLAGS.output_path)


if __name__ == "__main__":
  app.run(main)
