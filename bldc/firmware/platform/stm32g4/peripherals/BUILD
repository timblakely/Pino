load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

# TODO(blakely): Figure out a better way to deal with CMSIS defines globally.

cc_library(
    name = "dma",
    srcs = ["dma.cc"],
    hdrs = ["dma.h"],
    deps = [
        "//third_party/stm32cubeg4:stm32g474xx",
    ],
)

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
        "//pstd:constexpr_map",
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
        # "//bldc/firmware/platform/stm32g4/peripherals/timer:timer_defines",
    ],
)

cc_library(
    name = "rcc",
    srcs = ["rcc.cc"],
    deps = [
        ":flash",
        ":gpio",
        ":rcc_defines",
        # "//bldc/firmware/platform/stm32g4/peripherals/timer:timer_defines",
        "//third_party/mapbox/eternal",
        "//third_party/stm32cubeg4:stm32g474xx",
        "//bldc/firmware/platform/stm32g4/peripherals/systick",
    ],
)

cc_library(
    name = "spi_defines",
    hdrs = ["spi.h"],
)

cc_library(
    name = "spi",
    srcs = ["spi.cc"],
    deps = [
        ":dma",
        ":gpio",
        ":spi_defines",
        "//third_party/stm32cubeg4:stm32g474xx",
    ],
)
