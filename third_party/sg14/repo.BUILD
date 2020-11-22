load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

exports_files(glob(["**"]))

cc_library(
    name = "inplace_function",
    hdrs = [
        "SG14/inplace_function.h",
    ],
    include_prefix = "third_party/sg14",
    includes = ["."],
    strip_include_prefix = "SG14",
)
