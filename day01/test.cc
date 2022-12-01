#include "libaoc.h"

#include <gtest/gtest.h>
#include <sstream>

TEST(Part1Test, Test1) {
    std::vector <std::pair<std::string, uint32_t>> inputs = {
            {"",                                                   0},
            {"1000",                                               1000},
            {"1000\n2000",                                         3000},
            {"1000\n2000\n\n5000",                                 5000},
            {"1000\n2000\n\n5000\n\n1100\n1200\n1300\n1400\n1500", 6500},
    };

    for (auto &i : inputs) {
        std::stringstream s(i.first);
        EXPECT_EQ(max_calories(s), i.second) << " on input " << i.first;
    }
}

TEST(Part2Test, Test1) {
    std::vector <std::pair<std::string, uint32_t>> inputs = {
            {"1\n\n2\n\n3",                                                   6},
            {"1000\n2000\n\n5000\n\n1100\n1200\n1300\n1400\n1500",            14500},
            {"1\n2\n3\n\n100\n\n200\n300\n\n6000\n\n10000\n\n10000\n\n10000", 30000},
    };

    for (auto &i : inputs) {
        std::stringstream s(i.first);
        EXPECT_EQ(top_calories(s), i.second) << " on input " << i.first;
    }
}
