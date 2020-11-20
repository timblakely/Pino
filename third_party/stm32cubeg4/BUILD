load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "stm32g474xx",
    srcs = [
        "startup_stm32g474xx.s",
        "system_stm32g4xx.c",
    ],
    defines = [
        "STM32G474xx",  # Requried for CMSIS driver
    ],
    linkopts = ["-T $(location :stm32g474retx.ld)"],
    linkstatic = 1,
    deps = [
        ":stm32g474retx.ld",
        "//third_party/stm32cubeg4/cmsis",
        "@stm32cubeg4//:cmsis_device_includes",
    ],
)
