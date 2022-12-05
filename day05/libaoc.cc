#include "libaoc.h"

#include <map>
#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <algorithm>

std::string predict_top(std::istream &input) {
    std::string prediction;

    std::vector<std::vector<char>> stacks = {10,{}};

    bool header_done = false;
    std::string line;
    while (std::getline(input, line)) {
        if (header_done) {
            if (line.empty())
                continue;
            std::vector<std::string> toks;
            std::stringstream ss(line);
            std::string s;
            while (std::getline(ss, s, ' ')) {
                toks.push_back(s);
            }
            int num = std::stoi(toks[1]);
            int from = std::stoi(toks[3]);
            int to = std::stoi(toks[5]);
            for (int i = 0; i < num; ++i) {
                auto f = stacks[from-1].back();
                stacks[to-1].push_back(f);
                stacks[from-1].pop_back();
            }
        } else {
            if (line.at(1) == '1') {
                header_done = true;
                for (int i = 0; i < stacks.size(); ++i) {
                    auto s = stacks[i];
                    std::reverse(s.begin(), s.end());
                    stacks[i] = s;
                }
                continue;
            }
            for (int i = 0; i < line.size(); ++i) {
                if (line[i] != '[' && line[i] != ']' && line[i] != ' ') {
                    int stack_num = (i + 2) / 4;
                    stacks[stack_num].push_back(line[i]);
                }
            }
        }
    }

    for (auto s : stacks) {
        if (s.empty())
            continue;
        prediction += s.back();
    }

    return prediction;
}
std::string predict_top_9001(std::istream &input) {
    std::string prediction;

    std::vector<std::vector<char>> stacks = {10,{}};

    bool header_done = false;
    std::string line;
    while (std::getline(input, line)) {
        if (header_done) {
            if (line.empty())
                continue;
            std::vector<std::string> toks;
            std::stringstream ss(line);
            std::string s;
            while (std::getline(ss, s, ' ')) {
                toks.push_back(s);
            }
            int num = std::stoi(toks[1]);
            int from = std::stoi(toks[3]);
            int to = std::stoi(toks[5]);
            std::vector<char> t;
            for (int i = 0; i < num; ++i) {
                auto f = stacks[from-1].back();
                t.push_back(f);
                stacks[from-1].pop_back();
            }
            std::reverse(t.begin(), t.end());
            for (auto c:t) {
                stacks[to-1].push_back(c);
            }
        } else {
            if (line.at(1) == '1') {
                header_done = true;
                for (int i = 0; i < stacks.size(); ++i) {
                    auto s = stacks[i];
                    std::reverse(s.begin(), s.end());
                    stacks[i] = s;
                }
                continue;
            }
            for (int i = 0; i < line.size(); ++i) {
                if (line[i] != '[' && line[i] != ']' && line[i] != ' ') {
                    int stack_num = (i + 2) / 4;
                    stacks[stack_num].push_back(line[i]);
                }
            }
        }
    }

    for (auto s : stacks) {
        if (s.empty())
            continue;
        prediction += s.back();
    }

    return prediction;
}
