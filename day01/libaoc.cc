#include "libaoc.h"

#include <vector>

uint32_t top_n_calories(std::istream &input, int n) {
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

    uint32_t ret = 0;
    for (int i = 0; i < n; ++i) {
        ret += calories[i];
    }
    return ret;
}

uint32_t max_calories(std::istream &input) {
    return top_n_calories(input, 1);
}

uint32_t top_calories(std::istream &input) {
    return top_n_calories(input, 3);
}
