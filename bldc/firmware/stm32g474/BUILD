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
)

cc_library(
    name = "system",
    srcs = ["system.c"],
    hdrs = ["system.h"],
    deps = [
        "//third_party/stm32cubeg4:stm32g474xx",
    ],
    alwayslink = 1,
)
