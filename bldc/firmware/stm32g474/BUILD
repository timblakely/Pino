load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "cmsis_config",
    defines = [
        "__CM4_REV=1",
        "__MPU_PRESENT=1",
        "__NVIC_PRIO_BITS=4",
        "__Vendor_SysTickConfig=0",
        "__FPU_PRESENT=1",
    ],
    deps = [
        "//third_party/cmsis",
    ],
)

cc_library(
    name = "system_defines",
    hdrs = ["system.h"],
    alwayslink = 1,
)

cc_library(
    name = "system",
    srcs = ["system.cc"],
    deps = [
        ":system_defines",
        "//bldc/firmware/platform/stm32g4/peripherals:flash",
        "//bldc/firmware/platform/stm32g4/peripherals:fpu",
        "//bldc/firmware/platform/stm32g4/peripherals:nvic",
        "//bldc/firmware/platform/stm32g4/peripherals:rcc",
    ],
    alwayslink = 1,
)

cc_library(
    name = "led",
    srcs = ["led.cc"],
    hdrs = ["led.h"],
    deps = [
        "//bldc/firmware/platform/stm32g4/peripherals:gpio",
    ],
    alwayslink = 1,
)
