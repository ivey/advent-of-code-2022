#include "libaoc.h"

#include <gtest/gtest.h>
#include <sstream>

TEST(Part1Test, Test1) {
    std::vector <std::pair<std::string, uint32_t>> inputs = {
            {"vJrwpWtwJgWrhcsFMMfFFhFp", 16},
            {"jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL", 38},
            {"PmmdzqPrVvPwwTWBwg", 42},
            {"wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn", 22},
            {"ttgJtRGJQctTZtZT", 20},
            {"CrZsJsPPZsGzwwsLwLmpwMDw", 19}
    };

    for (auto &i : inputs) {
        EXPECT_EQ(duplicate_item_priority(i.first), i.second) << " on input " << i.first;
    }
}

TEST(Part1Test, Test2) {
    std::stringstream input("vJrwpWtwJgWrhcsFMMfFFhFp\n"
                              "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL\n"
                              "PmmdzqPrVvPwwTWBwg\n"
                              "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn\n"
                              "ttgJtRGJQctTZtZT\n"
                              "CrZsJsPPZsGzwwsLwLmpwMDw");
    EXPECT_EQ(duplicate_item_priorities(input), 157);
}

TEST(Part2Test, Test1) {
    std::string a("vJrwpWtwJgWrhcsFMMfFFhFp");
    std::string b("jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL");
    std::string c("PmmdzqPrVvPwwTWBwg");
    EXPECT_EQ(find_badge(a,b,c), 18);

    a = "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn";
    b = "ttgJtRGJQctTZtZT";
    c = "CrZsJsPPZsGzwwsLwLmpwMDw";
    EXPECT_EQ(find_badge(a,b,c), 52);
}

TEST(Part2Test, Test2) {
    std::stringstream input("vJrwpWtwJgWrhcsFMMfFFhFp\n"
                            "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL\n"
                            "PmmdzqPrVvPwwTWBwg\n"
                            "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn\n"
                            "ttgJtRGJQctTZtZT\n"
                            "CrZsJsPPZsGzwwsLwLmpwMDw");
    EXPECT_EQ(find_badges(input), 70);
}
