load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "interrupt_table",
    hdrs = ["interrupt_table.hpp"],
    deps = [
        "//third_party/sg14:inplace_function",
    ],
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        "//bldc/firmware/platform",
    ],
)

cc_binary(
    name = "test",
    srcs = select({
        ":bldc_a": ["a_test.cc"],
        ":bldc_b": ["b_test.cc"],
    }),
)
