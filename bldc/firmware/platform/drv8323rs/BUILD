load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

# TODO(blakely): Figure out a better way to deal with CMSIS defines globally.

cc_library(
    name = "drv8323rs",
    srcs = ["drv8323rs.cc"],
    hdrs = ["drv8323rs.h"],
    deps = [
        "//bldc/firmware/platform/stm32g4/peripherals:gpio",
        "//bldc/firmware/platform/stm32g4/peripherals:spi",
    ],
)
