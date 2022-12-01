load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

cc_library(
    name = "libpart1",
    srcs = ["libpart1.cc"],
    hdrs = ["libpart1.h"],
)

cc_library(
    name = "libpart2",
    srcs = ["libpart2.cc"],
    hdrs = ["libpart2.h"],
)

cc_test(
    name = "part1_test",
    size = "small",
    srcs = ["part1_test.cc"],
    deps = [
        ":libpart1",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "part2_test",
    size = "small",
    srcs = ["part2_test.cc"],
    deps = [
        ":libpart2",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_binary(
    name = "part1",
    srcs = ["part1.cc"],
    deps = [":libpart1"],
)

cc_binary(
    name = "part2",
    srcs = ["part2.cc"],
    deps = [":libpart2"],
)