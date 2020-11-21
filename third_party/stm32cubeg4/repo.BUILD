load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "cmsis_device_includes",
    hdrs = glob([
        "Drivers/CMSIS/Device/ST/STM32G4xx/Include/*.h",
    ]),
    include_prefix = "third_party/stm32cubeg4",
    includes = ["."],
    strip_include_prefix = "Drivers/CMSIS/Device/ST/STM32G4xx/Include",
)

cc_library(
    name = "cmsis_device_includes_globally_available",
    hdrs = glob([
        "Drivers/CMSIS/Device/ST/STM32G4xx/Include/*.h",
    ]),
    includes = ["."],
    strip_include_prefix = "Drivers/CMSIS/Device/ST/STM32G4xx/Include",
)

cc_library(
    name = "low_level_drivers",
    hdrs = glob([
        "Drivers/STM32G4xx_HAL_Driver/Inc/*_ll_*.h",
    ]),
    include_prefix = "third_party/stm32cubeg4",
    includes = ["."],
    strip_include_prefix = "Drivers/STM32G4xx_HAL_Driver/Inc/",
    deps = [
        ":cmsis_device_includes_globally_available",
    ],
)
