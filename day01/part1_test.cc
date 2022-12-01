#include "libpart1.h"

#include <gtest/gtest.h>
#include <sstream>

TEST(Part1Test, Test1) {
    std::vector<std::pair<std::string, uint32_t>> inputs = {
        {"", 0},
        {"1000", 1000},
        {"1000\n2000", 3000},
        {"1000\n2000\n\n5000", 5000},
        {"1000\n2000\n\n5000\n\n1100\n1200\n1300\n1400\n1500", 6500},
    };

    for (auto &i : inputs) {
        std::stringstream s(i.first);
        EXPECT_EQ(max_calories(s), i.second) << " on input " << i.first;
    }
}