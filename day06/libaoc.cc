#include "libaoc.h"

#include <map>
#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <unordered_set>


int detect_sop(std::istream &input) {
    return detect_unique_of_length(input, 4);
}

int detect_som(std::istream &input) {
    return detect_unique_of_length(input, 14);
}

int detect_unique_of_length(std::istream &input, int length) {
    int pos = 0;

    std::deque<char> last = {};
    last.resize(length);

    char c;
    while(input.get(c)) {
        pos++;
        last.push_back(c);
        last.pop_front();

        std::unordered_set<char> seen;
        for (char c : last) {
            seen.insert(c);
        }
        if (seen.size() == length && last.at(0) != 0) {
            break;
        }
    }

    return pos;
}
