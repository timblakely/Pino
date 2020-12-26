load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "g4_platform",
    srcs = ["g4_platform.cc"],
    hdrs = ["g4_platform.h"],
    deps = [
        "//bldc/firmware/platform:bldc_platform",
        "//bldc/firmware/platform/stm32g4/peripherals:flash",
        "//bldc/firmware/platform/stm32g4/peripherals:fpu",
        "//bldc/firmware/platform/stm32g4/peripherals:nvic",
        "//bldc/firmware/platform/stm32g4/peripherals:rcc",
        "//bldc/firmware/platform/stm32g4/peripherals:spi",
        "//bldc/firmware/stm32g474:led",
    ],
)
