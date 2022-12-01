load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

cc_library(
    name = "libaoc",
    srcs = ["libaoc.cc"],
    hdrs = ["libaoc.h"],
)

cc_test(
    name = "test",
    size = "small",
    srcs = ["test.cc"],
    deps = [
        ":libaoc",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_binary(
    name = "main",
    srcs = ["aoc.cc"],
    deps = [":libaoc"],
)
