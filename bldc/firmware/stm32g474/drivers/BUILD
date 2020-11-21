load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "flash",
    srcs = ["flash.cc"],
    hdrs = ["flash.h"],
    deps = [
        "//third_party/stm32cubeg4:stm32g474xx",
    ],
)

cc_library(
    name = "fpu",
    srcs = ["fpu.cc"],
    hdrs = ["fpu.h"],
    deps = [
        "//third_party/stm32cubeg4:stm32g474xx",
    ],
)

cc_library(
    name = "rcc",
    srcs = ["rcc.cc"],
    hdrs = ["rcc.h"],
    deps = [
        "//third_party/stm32cubeg4:stm32g474xx",
    ],
)
