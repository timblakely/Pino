load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

# Have to use exports_files since the cc_binary rule can't find linker files in
# non-direct-dependencies :/
exports_files([
    "startup_stm32g474xx.s",
])

# cc_library(
#     name = "stm32cubeg4",
#     deps = [
#         ":startup",
#     ],
# )

cc_library(
    name = "stm32g474xx",
    srcs = [
        "system_stm32g4xx.c",
    ],
    defines = [
        "STM32G474xx",  # Requried for CMSIS driver
    ],
    deps = [
        "@stm32cubeg4//:cmsis_includes",
    ],
)
