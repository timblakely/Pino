load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

# TODO(blakely): Figure out a better way to deal with CMSIS defines globally.

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
    name = "gpio_defines",
    hdrs = ["gpio.h"],
)

cc_library(
    name = "gpio",
    srcs = ["gpio.cc"],
    deps = [
        ":gpio_defines",
        ":rcc_defines",
        "//third_party/stm32cubeg4:stm32g474xx",
    ],
)

cc_library(
    name = "nvic_defines",
    hdrs = ["nvic.h"],
    deps = [
        "//bldc/firmware:interrupt_table",
    ],
)

cc_library(
    name = "nvic",
    srcs = ["nvic.cc"],
    hdrs = ["nvic.h"],
    deps = [
        ":rcc",
        "//bldc/firmware:interrupt_table",
        "//third_party/stm32cubeg4:stm32g474xx",
    ],
)

cc_library(
    name = "rcc_defines",
    hdrs = ["rcc.h"],
    deps = [
        ":gpio_defines",
        ":timer_defines",
    ],
)

cc_library(
    name = "rcc",
    srcs = ["rcc.cc"],
    deps = [
        ":flash",
        ":gpio",
        ":rcc_defines",
        ":timer",
        "//third_party/mapbox/eternal",
        "//third_party/stm32cubeg4:stm32g474xx",
    ],
)

cc_library(
    name = "timer_defines",
    hdrs = ["timer.h"],
)

cc_library(
    name = "timer",
    srcs = ["timer.cc"],
    deps = [
        ":nvic_defines",
        ":rcc_defines",
        "//third_party/stm32cubeg4:stm32g474xx",
    ],
    alwayslink = 1,
)
