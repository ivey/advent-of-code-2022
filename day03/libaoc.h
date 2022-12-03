#ifndef AOCDAY1_H_
#define AOCDAY1_H_

#include <cstdint>
#include <iosfwd>
#include <sstream>

uint32_t duplicate_item_priority(std::string &input);
uint32_t duplicate_item_priorities(std::istream &input);

uint32_t find_badge(std::string &a, std::string &b, std::string &c);
uint32_t find_badges(std::istream &inout);

#endif
