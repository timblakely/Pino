load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "core_includes_globally_available",
    hdrs = glob([
        "CMSIS/Core/Include/*.h",
    ]),
    includes = ["."],
    strip_include_prefix = "CMSIS/Core/Include",
)
