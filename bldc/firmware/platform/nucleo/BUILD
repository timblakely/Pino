load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "nucleo",
    srcs = ["setup.cc"],
)

platform(
    name = "g474re",
    constraint_values = [
        "//bldc/firmware/platform:nucleo",
    ],
    parents = ["//bldc/firmware/platform:common"],
)
