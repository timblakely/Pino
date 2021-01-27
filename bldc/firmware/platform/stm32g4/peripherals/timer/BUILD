load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

# cc_library(
#     name = "timer_defines",
#     hdrs = ["timer.h"],
# )

# cc_library(
#     name = "timer",
#     srcs = ["timer.cc"],
#     deps = [
#         "//bldc/firmware/platform/stm32g4/peripherals:nvic_defines",
#         "//bldc/firmware/platform/stm32g4/peripherals:rcc_defines",
#         # "//bldc/firmware/stm32g474:system_defines",
#         "//third_party/stm32cubeg4:stm32g474xx",
#     ],
#     alwayslink = 1,
# )

cc_library(
    name = "timer",
    srcs = [
        "timer.cc",
    ],
    hdrs = [
        "peripheral.h",
        "timer.h",
        "timer_adv_memory.inl",
        "timer_basic_memory.inl",
        "timer_gp_a_memory.inl",
        "timer_gp_b_memory.inl",
    ],
    deps = [
        "//bldc/firmware/platform/stm32g4/peripherals:nvic_defines",
        "//bldc/firmware/platform/stm32g4/peripherals:rcc_defines",
        "//third_party/etl:biffield",
        "//third_party/stm32cubeg4:stm32g474xx",
    ],
)
