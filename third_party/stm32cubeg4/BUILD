load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "stm32g474xx",
    hdrs = [
        "@stm32cubeg4//:Drivers/CMSIS/Device/ST/STM32G4xx/Include/stm32g474xx.h",
    ],
    deps = [
        ":stm32g4xx",
    ],
)

cc_library(
    name = "stm32g4xx",
    hdrs = [
        "@stm32cubeg4//:Drivers/CMSIS/Device/ST/STM32G4xx/Include/system_stm32g4xx.h",
    ],
)

# Have to use exports_files since the cc_binary rule can't find linker files in
# non-direct-dependencies :/
exports_files([
    "startup_stm32g474xx.s",
])
