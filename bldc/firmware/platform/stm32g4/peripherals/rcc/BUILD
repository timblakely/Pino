load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "peripheral",
    srcs = [
        "peripheral.cc",
    ],
    hdrs = [
        "peripheral.h",
        "rcc_memory.inl",
    ],
    deps = [
        "//bldc/firmware/platform/stm32g4/peripherals/timer:peripheral",
        "//third_party/etl:biffield",
    ],
)

# TODO(blakely): consolidate
cc_library(
    name = "rcc_defines",
    hdrs = ["rcc.h"],
    deps = [
        ":peripheral",
        "//bldc/firmware/platform/stm32g4/peripherals:gpio_defines",
        "//bldc/firmware/platform/stm32g4/peripherals/timer:peripheral",
    ],
)

cc_library(
    name = "rcc",
    srcs = [
        "rcc.cc",
    ],
    deps = [
        ":peripheral",
        ":rcc_defines",
        "//bldc/firmware/platform/stm32g4/peripherals:flash",
        "//bldc/firmware/platform/stm32g4/peripherals/systick",
        "//third_party/stm32cubeg4:stm32g474xx",
    ],
)
