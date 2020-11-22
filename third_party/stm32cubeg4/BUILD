load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "stm32g474_config",
    defines = [
        "STM32G474xx",
    ],
)

cc_library(
    name = "stm32g474xx",
    srcs = [
        "startup_stm32g474xx.s",
    ],
    linkopts = ["-T $(location :stm32g474retx.ld)"],
    linkstatic = 1,
    deps = [
        ":stm32g474_config",
        ":stm32g474retx.ld",
        "//third_party/cmsis:globally_available",
        "@stm32cubeg4//:cmsis_device_includes",
        "@stm32cubeg4//:low_level_drivers",
    ],
)
