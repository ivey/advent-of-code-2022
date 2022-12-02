#include "libaoc.h"

#include <iostream>
#include <map>

std::map<std::string, int> lookup = {{"A", 0},
                                     {"B", 1},
                                     {"C", 2},
                                     {"X", 0},
                                     {"Y", 1},
                                     {"Z", 2}
};

uint32_t guide_score(std::istream &input) {
    uint32_t score = 0;

    std::string line;
    while (std::getline(input, line)) {
        std::stringstream ss(line);
        std::string them, us;
        ss >> them;
        ss >> us;

        score += lookup[us] + 1;

        if (lookup[us] == lookup[them]) {
            std::cout << "T: " << them << " " << us << " tie \n";
            score += 3;
        } else {
            int v = lookup[us] - lookup[them];
            int r = v < 0 ? v + 3 : v;
            std::cout << "T: " << them << " " << us << " R: " << r << "\n";
            if ( r == 1) {
                score += 6;
            }
        }
    }

    return score;
}
