load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "peripheral",
    hdrs = [
        "peripheral.h",
        "timer_adv_memory.inl",
        "timer_basic_memory.inl",
        "timer_gp_a_memory.inl",
        "timer_gp_b_memory.inl",
    ],
    deps = [
        "//third_party/etl:biffield",
    ],
)

cc_library(
    name = "timer",
    srcs = [
        "timer.cc",
    ],
    hdrs = [
        "timer.h",
    ],
    deps = [
        ":peripheral",
        "//bldc/firmware/platform/stm32g4/peripherals:nvic_defines",
        "//bldc/firmware/platform/stm32g4/peripherals/rcc",
    ],
)
