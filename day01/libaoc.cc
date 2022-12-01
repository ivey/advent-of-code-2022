#include "libaoc.h"

#include <algorithm>
#include <istream>
#include <limits>
#include <ranges>
#include <utility>
#include <sstream>

uint32_t max_calories(std::istream &input) {
    uint32_t max = 0;
    uint32_t cur = 0;

    std::string line;

    while (std::getline(input, line)) {
        if (line == "") {
            if (cur > max) {
                max = cur;
            }
            cur = 0;
        } else {
            cur += std::stoi(line);
        }
    }
    if (cur > max) {
        max = cur;
    }
    return max;
};

uint32_t top_calories(std::istream &input) {
    uint32_t max1 = 0;
    uint32_t max2 = 0;
    uint32_t max3 = 0;
    uint32_t cur = 0;

    std::string line;

    while (std::getline(input, line)) {
        if (line == "") {
            if (cur > max1) {
                max3 = max2;
                max2 = max1;
                max1 = cur;
            }
            else if (cur > max2) {
                max3 = max2;
                max2 = cur;
            }
            else if (cur > max3) {
                max3 = cur;
            }
            cur = 0;
        } else {
            cur += std::stoi(line);
        }
    }
    if (cur > max1) {
        max3 = max2;
        max2 = max1;
        max1 = cur;
    }
    else if (cur > max2) {
        max3 = max2;
        max2 = cur;
    }
    else if (cur > max3) {
        max3 = cur;
    }
    return max1 + max2 + max3;
};