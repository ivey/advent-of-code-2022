#include "libaoc.h"

#include <gtest/gtest.h>
#include <sstream>

TEST(Part1Test, Test1) {
    std::stringstream input("    [D]    \n"
                            "[N] [C]    \n"
                            "[Z] [M] [P]\n"
                            " 1   2   3 \n"
                            "\n"
                            "move 1 from 2 to 1\n"
                            "move 3 from 1 to 3\n"
                            "move 2 from 2 to 1\n"
                            "move 1 from 1 to 2");
    EXPECT_EQ(predict_top(input), "CMZ");
}

TEST(Part2Test, Test1) {
    std::stringstream input("    [D]    \n"
                            "[N] [C]    \n"
                            "[Z] [M] [P]\n"
                            " 1   2   3 \n"
                            "\n"
                            "move 1 from 2 to 1\n"
                            "move 3 from 1 to 3\n"
                            "move 2 from 2 to 1\n"
                            "move 1 from 1 to 2");
    EXPECT_EQ(predict_top_9001(input), "MCD");
}
