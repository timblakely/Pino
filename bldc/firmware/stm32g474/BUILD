load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "system",
    srcs = ["system.c"],
    hdrs = ["system.h"],
    deps = [
        "//third_party/stm32cubeg4:stm32g474xx",
    ],
    alwayslink = 1,
)
