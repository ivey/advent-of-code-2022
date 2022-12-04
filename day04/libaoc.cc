#include "libaoc.h"

#include <map>
#include <iostream>
#include <tuple>

std::tuple<int,int> mktupl(std::string input) {
    auto p = input.find_first_of("-");
    auto first = input.substr(0, p);
    auto second = input.substr(p+1);
    return std::make_tuple(std::stoi(first),std::stoi(second));
}

uint32_t is_overlapping(std::string &input) {
    auto p = input.find_first_of(",");
    std::tuple<int,int> elf1 = mktupl(input.substr(0, p));
    std::tuple<int,int> elf2 = mktupl(input.substr(p+1));
    if ((std::get<0>(elf1) <= std::get<0>(elf2)) && (std::get<1>(elf1) >= std::get<1>(elf2)))
        return 1;
    if ((std::get<0>(elf2) <= std::get<0>(elf1)) && (std::get<1>(elf2) >= std::get<1>(elf1)))
        return 1;
    return 0;
}

uint32_t count_overlapping(std::istream &input) {
    uint32_t score = 0;

    std::string line;
    while (std::getline(input, line)) {
        score += is_overlapping(line);
    }

    return score;
}

uint32_t is_partially_overlapping(std::string &input) {
    auto p = input.find_first_of(",");
    std::tuple<int,int> elf1 = mktupl(input.substr(0, p));
    std::tuple<int,int> elf2 = mktupl(input.substr(p+1));
    if ((std::get<0>(elf1) <= std::get<0>(elf2)) && (std::get<1>(elf1) >= std::get<0>(elf2)))
        return 1;
    if ((std::get<0>(elf2) <= std::get<0>(elf1)) && (std::get<1>(elf2) >= std::get<0>(elf1)))
        return 1;
    return 0;
}

uint32_t count_partially_overlapping(std::istream &input) {
    uint32_t score = 0;

    std::string line;
    while (std::getline(input, line)) {
        score += is_partially_overlapping(line);
    }

    return score;
}
