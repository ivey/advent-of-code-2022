#include "libaoc.h"

#include <gtest/gtest.h>
#include <sstream>

TEST(Part1Test, Test1) {
    std::vector <std::pair<std::string, uint32_t>> inputs = {
            {"A Y\nB X\nC Z", 15},
            {"B Z\nC Z\nC Z\nA Y\nB Z\nC Y", 40}
    };

    for (auto &i : inputs) {
        std::stringstream s(i.first);
        EXPECT_EQ(guide_score(s), i.second) << " on input " << i.first;
    }
}

TEST(Part2Test, Test1) {
    std::vector <std::pair<std::string, uint32_t>> inputs = {
            {"A Y", 4},
            {"A Y\nB X", 5},
            {"C Z", 7},
            {"A Y\nB X\nC Z", 12},
    };

    for (auto &i : inputs) {
        std::stringstream s(i.first);
        EXPECT_EQ(guide_score2(s), i.second) << " on input " << i.first;
    }
}
