load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "systick",
    srcs = ["systick.cc"],
    hdrs = ["systick.h"],
    deps = [
        "//bldc/firmware/platform/stm32g4/peripherals:nvic_defines",
        "//bldc/firmware/platform/stm32g4/peripherals:rcc_defines",
        "//third_party/stm32cubeg4:stm32g474xx",
    ],
    alwayslink = 1,
)
