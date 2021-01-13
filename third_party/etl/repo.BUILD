load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "biffield",
    hdrs = glob(["biffield/*.h"]),
    include_prefix = "third_party/etl/biffield",
    includes = ["."],
    strip_include_prefix = "biffield",
)
