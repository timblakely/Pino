load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "nucleo",
    srcs = ["setup.cc"],
    deps = [
        "//bldc/firmware/platform:system",
        "//bldc/firmware/stm32g474:led",
        "//bldc/firmware/stm32g474/drivers:flash",
        "//bldc/firmware/stm32g474/drivers:fpu",
        "//bldc/firmware/stm32g474/drivers:nvic",
        "//bldc/firmware/stm32g474/drivers:rcc",
    ],
)

platform(
    name = "g474re",
    constraint_values = [
        "//bldc/firmware/platform:nucleo",
    ],
    parents = ["//bldc/firmware/platform:common"],
)
