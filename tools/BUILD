load("@pip//:requirements.bzl", "requirement")
load("@rules_python//python:defs.bzl", "py_binary")

py_binary(
    name = "gen_biffields",
    srcs = ["gen_biffields.py"],
    data = [
        "//third_party/stm32cubeg4:STM32G474xx.svd",
        "@etl//:biffield_headers",
        # "//third_party/etl:biffield_headers",
    ],
    deps = [
        requirement("absl-py"),
        requirement("cmsis-svd"),
        requirement("svdtools"),
        "@rules_python//python/runfiles",
    ],
)

py_binary(
    name = "patch_svd",
    srcs = ["patch_svd.py"],
    data = [
        "//third_party/stm32cubeg4:STM32G474xx.svd",
    ],
    deps = [
        requirement("absl-py"),
        requirement("svdtools"),
        "@bazel_tools//tools/python/runfiles",
    ],
)
