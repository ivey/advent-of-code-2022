#include "libaoc.h"

#include <gtest/gtest.h>
#include <sstream>

TEST(Part1Test, Test1) {
    std::vector <std::pair<std::string, uint32_t>> inputs = {
            {"mjqjpqmgbljsphdztnvjfqwrcgsmlb",7},
            {"bvwbjplbgvbhsrlpgdmjqwftvncz",5},
            {"nppdvjthqldpwncqszvftbrmjlhg",6},
            {"nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg",10},
            {"zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw",11},
    };

    for (auto &i : inputs) {
        std::stringstream ss(i.first);
        EXPECT_EQ(detect_sop(ss), i.second) << " on input " << i.first;
    }
}

TEST(Part2Test, Test1) {
    std::vector <std::pair<std::string, uint32_t>> inputs = {
            {"mjqjpqmgbljsphdztnvjfqwrcgsmlb",19},
            {"bvwbjplbgvbhsrlpgdmjqwftvncz",23},
            {"nppdvjthqldpwncqszvftbrmjlhg",23},
            {"nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg",29},
            {"zcfzfwzzqfrljwzlrfnpqdbhtmscgvjw",26}
    };

    for (auto &i : inputs) {
        std::stringstream ss(i.first);
        EXPECT_EQ(detect_som(ss), i.second) << " on input " << i.first;
    }
}
