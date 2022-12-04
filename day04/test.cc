#include "libaoc.h"

#include <gtest/gtest.h>
#include <sstream>

TEST(Part1Test, Test1) {
    std::vector <std::pair<std::string, uint32_t>> inputs = {
            {"2-4,6-8",0},
            {"2-3,4-5",0},
            {"5-7,7-9",0},
            {"2-8,3-7",1},
            {"6-6,4-6",1},
            {"2-6,4-8",0},
    };

    for (auto &i : inputs) {
        EXPECT_EQ(is_overlapping(i.first), i.second) << " on input " << i.first;
    }
}


TEST(Part2Test, Test1) {
    std::vector <std::pair<std::string, uint32_t>> inputs = {
            {"2-4,6-8",0},
            {"2-3,4-5",0},
            {"5-7,7-9",1},
            {"2-8,3-7",1},
            {"6-6,4-6",1},
            {"2-6,4-8",1},
    };

    for (auto &i : inputs) {
        EXPECT_EQ(is_partially_overlapping(i.first), i.second) << " on input " << i.first;
    }
}
