load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        "//bldc/firmware/stm32g474:system",
        "//third_party/stm32cubeg4:stm32g474xx",
    ],
)
