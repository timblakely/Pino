load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

package(default_visibility = ["//visibility:public"])

platform(
    name = "common",
    constraint_values = ["@platforms//cpu:armv7"],
    # constraint_values = [
    #     "@platforms//cpu:x86_64",
    #     "@platforms//os:linux",
    # ],
)

constraint_setting(name = "micro")

constraint_value(
    name = "stm32g4",
    constraint_setting = ":micro",
)

constraint_setting(name = "board")

constraint_value(
    name = "devboard",
    constraint_setting = ":board",
)

constraint_value(
    name = "nucleo",
    constraint_setting = ":board",
)

# Aliases

platform(
    name = "devboard_v1",
    parents = ["//bldc/firmware/platform/stm32g4/devboard:v1"],
)

cc_library(
    name = "bldc_platform",
    srcs = [
        "bldc_platform.cc",
    ],
    hdrs = ["bldc_platform.h"],
)

cc_library(
    name = "platform",
    deps = [
        ":bldc_platform",
    ] + select({
        ":devboard": ["//bldc/firmware/platform/stm32g4/devboard"],
        ":nucleo": ["//bldc/firmware/platform/stm32g4/nucleo"],
    }),
    alwayslink = 1,
)

cc_binary(
    name = "platform_test",
    srcs = ["platform_test.cc"],
    deps = [
        ":platform",
    ],
)
