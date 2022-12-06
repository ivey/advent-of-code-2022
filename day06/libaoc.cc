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
    int pos = 0;

    std::deque<char> last4 = {};
    last4.resize(4);
    char c;
    while(input.get(c)) {
        pos++;
        last4.push_back(c);
        last4.pop_front();
        if (last4[0] != 0 && last4[0] != last4[1] && last4[0] != last4[2] && last4[0] != last4[3] && last4[1] != last4[2] && last4[1] != last4[3] && last4[2] != last4[3]) {
            break;
        }
    }

    return pos;
}

int detect_som(std::istream &input) {
    int pos = 0;

    std::deque<char> last14 = {};
    last14.resize(14);

    char c;
    while(input.get(c)) {
        pos++;
        last14.push_back(c);
        last14.pop_front();

        std::unordered_set<char> seen;
        for (char c : last14) {
            seen.insert(c);
        }
        if (seen.size() == 14) {
            break;
        }
    }

    return pos;
}
