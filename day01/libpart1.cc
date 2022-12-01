#include "libpart1.h"

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