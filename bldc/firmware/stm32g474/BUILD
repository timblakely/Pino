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
    name = "init",
    srcs = ["init.cc"],
    hdrs = ["init.h"],
    deps = [
        "//bldc/firmware/stm32g474/drivers:flash",
        "//bldc/firmware/stm32g474/drivers:fpu",
        "//bldc/firmware/stm32g474/drivers:nvic",
        "//bldc/firmware/stm32g474/drivers:rcc",
    ],
    alwayslink = 1,
)

cc_library(
    name = "interrupt_table",
    srcs = ["interrupt_table.cc"],
    hdrs = ["interrupt_table.h"],
    deps = [
        "//bldc/firmware:interrupt_table",
        "//bldc/firmware/stm32g474/drivers:nvic",
    ],
    alwayslink = 1,
)

cc_library(
    name = "led",
    srcs = ["led.cc"],
    hdrs = ["led.h"],
    deps = [
        "//bldc/firmware/stm32g474/drivers:gpio",
    ],
    alwayslink = 1,
)
