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
    name = "bldc",
    constraint_setting = ":board",
)

constraint_value(
    name = "nucleo",
    constraint_setting = ":board",
)

cc_library(
    name = "system",
    srcs = [
        "system.cc",
    ],
    hdrs = ["system.h"],
)

cc_library(
    name = "platform",
    deps = [
        ":system",
    ] + select({
        ":bldc": ["//bldc/firmware/platform/bldc"],
        ":nucleo": ["//bldc/firmware/platform/nucleo"],
    }),
    alwayslink = 1,
)
# srcs = [
#         "system.cc",
#     ],

cc_binary(
    name = "platform_test",
    srcs = ["platform_test.cc"],
    deps = [
        ":platform",
    ],
)
