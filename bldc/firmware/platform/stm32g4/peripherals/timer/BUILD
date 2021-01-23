load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "timer_defines",
    hdrs = ["timer.h"],
)

cc_library(
    name = "timer",
    srcs = ["timer.cc"],
    deps = [
        "//bldc/firmware/platform/stm32g4/peripherals:nvic_defines",
        "//bldc/firmware/platform/stm32g4/peripherals:rcc_defines",
        # "//bldc/firmware/stm32g474:system_defines",
        "//third_party/stm32cubeg4:stm32g474xx",
    ],
    alwayslink = 1,
)
