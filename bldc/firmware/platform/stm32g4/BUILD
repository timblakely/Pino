load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "can_messages",
    hdrs = ["can_messages.h"],
    deps = [
        "//bldc/firmware/platform/stm32g4/peripherals/can",
    ],
)

cc_library(
    name = "g4_platform",
    srcs = ["g4_platform.cc"],
    hdrs = ["g4_platform.h"],
    deps = [
        ":can_messages",
        "//bldc/firmware/platform:bldc_platform",
        "//bldc/firmware/platform/drv8323rs",
        "//bldc/firmware/platform/ma702",
        "//bldc/firmware/platform/stm32g4/peripherals:flash",
        "//bldc/firmware/platform/stm32g4/peripherals:fpu",
        "//bldc/firmware/platform/stm32g4/peripherals:nvic",
        "//bldc/firmware/platform/stm32g4/peripherals:spi",
        "//bldc/firmware/platform/stm32g4/peripherals/can",
        "//bldc/firmware/platform/stm32g4/peripherals/rcc",
        "//bldc/firmware/platform/stm32g4/peripherals/timer",
        "//bldc/firmware/stm32g474:led",
    ],
)
