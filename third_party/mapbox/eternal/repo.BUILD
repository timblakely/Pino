load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "eternal",
    hdrs = [
        "include/mapbox/eternal.hpp",
    ],
    include_prefix = "third_party/mapbox/eternal",
    includes = ["."],
    strip_include_prefix = "include/mapbox/",
)
