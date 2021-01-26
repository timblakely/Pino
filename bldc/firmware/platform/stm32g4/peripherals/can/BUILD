load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

# TODO(blakely): Figure out a better way to deal with CMSIS defines globally.

cc_library(
    name = "can",
    srcs = [
        "can.cc",
        "extended_filter_memory.inl",
        "fdcan_memory.inl",
        "peripheral.cc",
        "rx_buffer_memory.inl",
        "standard_filter.cc",
        "standard_filter_memory.inl",
        "tx_buffer.cc",
        "tx_buffer_memory.inl",
        "tx_event_memory.inl",
    ],
    hdrs = [
        "can.h",
        "extended_filter.h",
        "frame.h",
        "peripheral.h",
        "rx_buffer.h",
        "standard_filter.h",
        "tx_buffer.h",
        "tx_event.h",
    ],
    deps = [
        "//bldc/firmware/platform/stm32g4/peripherals:gpio_defines",
        "//bldc/firmware/platform/stm32g4/peripherals:nvic",
        "//third_party/etl:biffield",
        "//third_party/sg14:inplace_function",
        "//third_party/stm32cubeg4:stm32g474xx",
    ],
)
