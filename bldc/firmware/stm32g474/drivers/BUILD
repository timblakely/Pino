load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "flash",
    srcs = ["flash.cc"],
    hdrs = ["flash.h"],
    deps = [
        "//third_party/stm32cubeg4:stm32g474xx",
    ],
)

cc_library(
    name = "fpu",
    srcs = ["fpu.cc"],
    hdrs = ["fpu.h"],
    deps = [
        "//third_party/stm32cubeg4:stm32g474xx",
    ],
)

cc_library(
    name = "nvic",
    srcs = ["nvic.cc"],
    hdrs = ["nvic.h"],
    deps = [
        # TODO(blakely): Figure out a better way to deal with CMSIS defines
        # globally.
        ":rcc",
        "//bldc/firmware/stm32g474:cmsis_config",
        "//third_party/stm32cubeg4:stm32g474xx",
    ],
)

cc_library(
    name = "rcc",
    srcs = ["rcc.cc"],
    hdrs = ["rcc.h"],
    deps = [
        "//third_party/stm32cubeg4:stm32g474xx",
    ],
)
