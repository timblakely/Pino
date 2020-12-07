load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "bldc",
    srcs = select({
        ":swap_green_blue_led": ["setup_dev.cc"],
        "//conditions:default": ["setup.cc"],
    }),
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
