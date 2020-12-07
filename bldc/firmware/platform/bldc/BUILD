load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "bldc",
    srcs = select({
        ":swap_green_blue_led": ["setup_v1_dev.cc"],
        "//conditions:default": ["setup_v1.cc"],
    }),
    deps = [
        "//bldc/firmware/platform:system",
        "//bldc/firmware/stm32g474:led",
        "//bldc/firmware/stm32g474/drivers:flash",
        "//bldc/firmware/stm32g474/drivers:fpu",
        "//bldc/firmware/stm32g474/drivers:nvic",
        "//bldc/firmware/stm32g474/drivers:rcc",
    ],
)

constraint_setting(
    name = "errata",
)

constraint_value(
    name = "swap_green_blue_led",
    constraint_setting = ":errata",
)

platform(
    name = "v1",
    constraint_values = [
        "//bldc/firmware/platform:bldc",
    ],
    parents = ["//bldc/firmware/platform:common"],
)

platform(
    name = "v1_dev",
    constraint_values = [
        ":swap_green_blue_led",
    ],
    parents = [":v1"],
)
