#include <fstream>
#include <iostream>

#include "libaoc.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "This program expects one parameter that is the input file to read.\n";
        return 1;
    }
    std::ifstream input(argv[1]);
    if (!input.is_open()) {
        std::cerr << "Failed to open file.\n";
        return 1;
    }

    std::cout << "Part 1: score: " << detect_sop(input) << "\n";
    input.clear();
    input.seekg(0, std::ios::beg);
    std::cout << "Part 2: score: " << detect_som(input) << "\n";

    return 0;
}
