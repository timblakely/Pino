load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "g4_platform",
    srcs = ["g4_platform.cc"],
    hdrs = ["g4_platform.h"],
    deps = [
        "//bldc/firmware/platform:bldc_platform",
        "//bldc/firmware/stm32g474:led",
        "//bldc/firmware/stm32g474/drivers:flash",
        "//bldc/firmware/stm32g474/drivers:fpu",
        "//bldc/firmware/stm32g474/drivers:nvic",
        "//bldc/firmware/stm32g474/drivers:rcc",
    ],
)
