#include "libaoc.h"

#include <gtest/gtest.h>
#include <sstream>

TEST(Part1Test, Test1) {
    std::stringstream input("30373\n"
                            "25512\n"
                            "65332\n"
                            "33549\n"
                            "35390");

    EXPECT_EQ(visible_trees(input), 21);
}

TEST(Part2Test, Test1) {
    std::stringstream input("30373\n"
                            "25512\n"
                            "65332\n"
                            "33549\n"
                            "35390");

    EXPECT_EQ(max_scenic_score(input), 8);
}
