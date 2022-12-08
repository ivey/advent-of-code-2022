#include "libaoc.h"

#include <map>
#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <unordered_set>


int visible_trees(std::istream &input) {
    int size = 0;

    std::vector<std::vector<int>> grid;
    std::vector<std::vector<int>> visgrid;

    std::string line;
    int row = 0;
    int col = 0;
    while (std::getline(input, line)) {
        grid.push_back({});
        visgrid.push_back({});
        for (auto c : line) {
            grid[row].push_back(atoi(&c));
            visgrid[row].push_back(0);
            col++;
        }
        row++;
        col = 0;
    }

    int prev = -1;
    // check each row, both ways
    for (int y = 0; y < grid[0].size(); ++y) {
        prev = -1;
        for (int x = 0; x < grid.size(); ++x) {
            if (grid[x][y] > prev) {
                visgrid[x][y] = 1;
                prev = std::max(prev, grid[x][y]);
            }
        }
        prev = -1;
        for (int x = grid.size() - 1; x >= 0; x--) {
            if (grid[x][y] > prev) {
                visgrid[x][y] = 1;
                prev = std::max(prev, grid[x][y]);
            }
        }
    }

    // check each col, both ways
    for (int x = 0; x < grid.size(); ++x) {
        prev = -1;
        for (int y = 0; y < grid[0].size(); ++y) {
            if (grid[x][y] > prev) {
                visgrid[x][y] = 1;
                prev = std::max(prev, grid[x][y]);
            }
        }
        prev = -1;
        for (int y = grid[0].size() - 1; y >= 0; y--) {
            if (grid[x][y] > prev) {
                visgrid[x][y] = 1;
                prev = std::max(prev, grid[x][y]);
            }
        }
    }

    for (auto row : visgrid) {
        for (auto col : row) {
//            std::cout << col;
            size += col;
        }
//        std::cout << "\n";
    }

    return size;
}


int max_scenic_score(std::istream &input) {
    std::vector<std::vector<int>> grid;

    std::string line;
    int row = 0;
    int col = 0;
    while (std::getline(input, line)) {
        grid.push_back({});
        for (auto c : line) {
            grid[row].push_back(atoi(&c));
            col++;
        }
        row++;
        col = 0;
    }

    int max = 0;

    for (int x = 0; x < grid[0].size(); ++x) {
        for (int y = 0; y < grid.size(); ++y) {
//            std::cout << "processing "<<x<<","<<y<<" "<<grid[y][x]<<"\n";

            int up = 0;
            for (int i = y-1; i >= 0; --i) {
                up++;
//                std::cout << "UP " << x<<","<<i<<" "<<grid[i][x]<<"\n";
                if (grid[i][x] >= grid[y][x]) {
                    break;
                }
            }

            int left = 0;
            for (int i = x-1; i >= 0; --i) {
                left++;
//                std::cout << "LEFT " << i<<","<<y<<" "<<grid[y][i]<<"\n";
                if (grid[y][i] >= grid[y][x]) {
                    break;
                }
            }

            int down = 0;
            for (int i = y+1; i < grid.size(); ++i) {
                down++;
//                std::cout << "DOWN " << x<<","<<i<<" "<<grid[i][x]<<"\n";
                if (grid[i][x] >= grid[y][x]) {
                    break;
                }
            }

            int right = 0;
            for (int i = x+1; i < grid.size(); ++i) {
                right++;
//                std::cout << "RIGHT " << x<<","<<i<<" "<<grid[i][x]<<"\n";
                if (grid[y][i] >= grid[y][x]) {
                    break;
                }
            }

            int score = up*down*left*right;
//            if (x==2 && y ==3) {
//                std::cout << x << "," << y << " " << grid[y][x] << "(" << up << "*" << left << "*" << down  << "*" << right << ") =" << score << "\n";
//            }
            max = std::max(max, score);
        }
    }

    return max;
}
