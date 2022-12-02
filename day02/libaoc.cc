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

int mymod3(int v) {
    return v < 0 ? v + 3 : v;
}

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
            score += 3;
        } else {
            int r = mymod3(lookup[us] - lookup[them]);
            if ( r == 1) {
                score += 6;
            }
        }
    }

    return score;
}

uint32_t guide_score2(std::istream &input) {
    uint32_t score = 0;

    std::string line;
    while (std::getline(input, line)) {
        std::stringstream ss(line);
        std::string them, outcome;
        ss >> them;
        ss >> outcome;

        if (outcome == "X") {
            score += mymod3(lookup[them] - 1) + 1;
        } else if (outcome == "Y") {
            score += 3; // draw
            score += lookup[them] + 1;
        } else if (outcome == "Z") {
            score += 6; //win
            score += mymod3(lookup[them] - 2) + 1;
        }
    }

    return score;
}
