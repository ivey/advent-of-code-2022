#include "libaoc.h"

#include <map>
#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <unordered_set>


int sum_small_dirs(std::istream &input) {
    int size = 0;
    std::vector<std::string> dirstack;
    std::map<std::string,int> dirsizes;

    std::string line;
    bool in_ls = false;

    while (std::getline(input, line)) {
        if (in_ls) {
            if (line.rfind("$", 0) == 0) {
                in_ls = false; // fall to cmd processing
            } else if (line.rfind("dir ",0) == 0) {
                // do nothing
            } else {
                // this is the file list case
                auto p = line.find_first_of(' ');
                auto size = std::stoi(line.substr(0, p));
//                std::cout << "---\n";
                for (auto dir : dirstack) {
//                    std::cout << dir << " " << size << "\n";
                    dirsizes[dir] += size; // parents include children
                }
            }
        }

        // cmd processing
        if (line.rfind("$ cd ", 0) == 0) {
            auto dir = line.substr(5);
            if (dir == "..") {
                dirstack.pop_back();
            } else {
                std::string newdir = "";
                if (!dirstack.empty()) {
                    newdir.append(dirstack.back());
                }
                newdir.append(dir);
                dirstack.push_back(newdir);
            }
        } else if (line.rfind("$ ls", 0) == 0) {
            in_ls = true;
        }
    }

//    std::cout << "=====\n";

    for (auto dir : dirsizes) {
        if (dir.second <= 100000) {
//            std::cout << dir.first << " " << dir.second << "\n";
            size += dir.second;
        }
    }
    return size;
}

int find_delete_target(std::istream &input) {
    std::vector<std::string> dirstack;
    std::map<std::string,int> dirsizes;

    std::string line;
    bool in_ls = false;

    while (std::getline(input, line)) {
        if (in_ls) {
            if (line.rfind("$", 0) == 0) {
                in_ls = false; // fall to cmd processing
            } else if (line.rfind("dir ",0) == 0) {
                // do nothing
            } else {
                // this is the file list case
                auto p = line.find_first_of(' ');
                auto size = std::stoi(line.substr(0, p));
//                std::cout << "---\n";
                for (auto dir : dirstack) {
//                    std::cout << dir << " " << size << "\n";
                    dirsizes[dir] += size; // parents include children
                }
            }
        }

        // cmd processing
        if (line.rfind("$ cd ", 0) == 0) {
            auto dir = line.substr(5);
            if (dir == "..") {
                dirstack.pop_back();
            } else {
                std::string newdir = "";
                if (!dirstack.empty()) {
                    newdir.append(dirstack.back());
                }
                newdir.append(dir);
                dirstack.push_back(newdir);
            }
        } else if (line.rfind("$ ls", 0) == 0) {
            in_ls = true;
        }
    }

//    std::cout << "=====\n";

    auto free = 70000000 - dirsizes["/"];
    auto needed = 30000000 - free;
    int smallest = 30000000;

    for (auto dir : dirsizes) {
        if (dir.second >= needed && dir.second < smallest) {
//            std::cout << dir.first << " " << dir.second << "\n";
            smallest = dir.second;
        }
    }
    return smallest;
}
