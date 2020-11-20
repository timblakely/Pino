load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "cmsis_includes",
    hdrs = glob([
        "Drivers/CMSIS/Device/ST/STM32G4xx/Include/*.h",
    ]),
    include_prefix = "third_party/stm32cubeg4",
    includes = ["."],
    strip_include_prefix = "Drivers/CMSIS/Device/ST/STM32G4xx/Include",
)

cc_library(
    name = "cmsis_includes_stripped",
    hdrs = glob([
        "Drivers/CMSIS/Device/ST/STM32G4xx/Include/*.h",
    ]),
    includes = ["."],
    strip_include_prefix = "Drivers/CMSIS/Device/ST/STM32G4xx/Include",
)
