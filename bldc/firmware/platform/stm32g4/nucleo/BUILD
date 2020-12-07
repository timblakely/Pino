load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "nucleo",
    srcs = ["setup.cc"],
    deps = [
        "//bldc/firmware/platform:system",
        "//bldc/firmware/platform/stm32g4/peripherals:flash",
        "//bldc/firmware/platform/stm32g4/peripherals:fpu",
        "//bldc/firmware/platform/stm32g4/peripherals:nvic",
        "//bldc/firmware/platform/stm32g4/peripherals:rcc",
        "//bldc/firmware/stm32g474:led",
    ],
)

platform(
    name = "g474re",
    constraint_values = [
        "//bldc/firmware/platform:nucleo",
    ],
    parents = ["//bldc/firmware/platform:common"],
)
