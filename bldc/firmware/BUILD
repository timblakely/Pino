load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        "//bldc/firmware/stm32g474:system",
        "//bldc/firmware/stm32g474/drivers:flash",
        "//bldc/firmware/stm32g474/drivers:fpu",
        "//bldc/firmware/stm32g474/drivers:nvic",
        "//bldc/firmware/stm32g474/drivers:rcc",
    ],
)
