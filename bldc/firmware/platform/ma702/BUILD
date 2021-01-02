load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

# TODO(blakely): Figure out a better way to deal with CMSIS defines globally.

cc_library(
    name = "ma702",
    srcs = ["ma702.cc"],
    hdrs = ["ma702.h"],
    deps = [
        "//bldc/firmware/platform/stm32g4/peripherals:dma",
        "//bldc/firmware/platform/stm32g4/peripherals:spi",
    ],
)
