#include "libaoc.h"

#include <vector>
#include <functional>

uint32_t max_calories(std::istream &input) {
    uint32_t max = 0;
    uint32_t cur = 0;

    std::string line;

    while (std::getline(input, line)) {
        if (line == "") {
            cur = 0;
        } else {
            cur += std::stoi(line);
        }
        max = std::max(cur, max);
    }
    return max;
}

uint32_t top_calories(std::istream &input) {
    uint32_t cur = 0;

    std::string line;
    auto calories = std::vector < uint32_t > {};

    while (std::getline(input, line)) {
        if (line == "") {
            calories.emplace_back(cur);
            cur = 0;
        } else {
            cur += std::stoi(line);
        }
    }
    calories.emplace_back(cur);
    std::sort(calories.begin(), calories.end(), std::greater<uint32_t>());
    return calories[0] + calories[1] + calories[2];
}
