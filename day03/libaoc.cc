#include "libaoc.h"

#include <map>
#include <iostream>

// just use the chars, no need to remember the ASCII offset, inspired by @jblazquez
int priority(char c) {
    return c >= 'a' ? (c - 'a' + 1) : (c - 'A' + 27);
}

uint32_t duplicate_item_priority(std::string &input) {
    std::map<char, int> freq = {};

    int pivot = input.length() / 2;
    std::string first = input.substr(0, pivot);
    std::string second = input.substr(pivot);

    for (char c: first) {
        freq[c]++;
    }

    for (char c: second) {
        if (freq[c] != 0) {
            return priority(c);
        }
    }

    return 0;
}

uint32_t duplicate_item_priorities(std::istream &input) {
    uint32_t score = 0;

    std::string line;
    while (std::getline(input, line)) {
        score += duplicate_item_priority(line);
    }

    return score;
}

uint32_t find_badge(std::string &first, std::string &second, std::string &third) {
    std::map<char, int> freqa = {};
    std::map<char, int> freqb = {};

    for (char c : first) {
        freqa[c]++;
    }

    for (char c : second) {
        if (freqa[c] > 0) {
            freqb[c]++;
        }
    }

    for (char c : third) {
        if (freqb[c] > 0) {
            return priority(c);
        }
    }
    return 0;
}

uint32_t find_badges(std::istream &input) {
    uint32_t score = 0;

    std::string a, b, c;

    while (std::getline(input, a))
    {
        std::getline(input, b);
        std::getline(input, c);
        score += find_badge(a,b,c);
    }

    return score;
}
