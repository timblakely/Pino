load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "devboard",
    srcs = ["devboard.cc"],
    # TODO(blakely): handle selecting on errata/revisions
    # srcs = select({
    #     ":swap_green_blue_led": ["system_swap.cc"],
    #     # "//conditions:default": ["system.cc"],
    # }),
    hdrs = ["devboard.h"],
    deps = [
        "//bldc/firmware/platform/stm32g4:g4_platform",
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
        "//bldc/firmware/platform:devboard",
    ],
    parents = ["//bldc/firmware/platform:common"],
)
