load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

# TODO(blakely): Figure out a better way to deal with CMSIS defines globally.

cc_library(
    name = "can",
    srcs = [
        "can.cc",
        "extended_filter_memory.inl",
        "fdcan.cc",
        "fdcan.inl",
        "rx_buffer_memory.inl",
        "standard_filter_memory.inl",
        "tx_buffer_memory.inl",
        "tx_event_memory.inl",
    ],
    hdrs = [
        "can.h",
        "fdcan.h",
    ],
    deps = [
        "//bldc/firmware/platform/stm32g4/peripherals:gpio_defines",
        "//third_party/etl:biffield",
        "//third_party/stm32cubeg4:stm32g474xx",
    ],
)
