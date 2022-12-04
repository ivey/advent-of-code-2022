#ifndef AOCDAY4_H_
#define AOCDAY4_H_

#include <cstdint>
#include <iosfwd>
#include <sstream>

uint32_t is_overlapping(std::string &input);
uint32_t count_overlapping(std::istream &input);
uint32_t is_partially_overlapping(std::string &input);
uint32_t count_partially_overlapping(std::istream &input);

#endif
