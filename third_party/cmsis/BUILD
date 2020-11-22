load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "cmsis",
    deps = [
        "@cmsis//:core_includes",
    ],
)

cc_library(
    name = "globally_available",
    deps = [
        "@cmsis//:core_includes_globally_available",
    ],
)
