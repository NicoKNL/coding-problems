#include <bits/stdc++.h>
using namespace std;

int main() {
    // grab input file
    ifstream infile("../advent-of-code-2020/input/03.txt");
    if (!infile.is_open()) {
        return -1;
    }

    vector<vector<char>> grid;

    string line = "";
    while (getline(infile, line)) {
        vector<char> row;
        for (char c : line) {
            row.emplace_back(c);
        }
        grid.emplace_back(row);
    }

    int offset_x = 3;
    int offset_y = 1;
    int trees = 0;

    int x = 0;
    int y = 0;

    while (y < grid.size()) {
        if (grid[y][x] == '#') ++trees;
        x = (x + offset_x) % grid[0].size();
        y += offset_y;
    }

    printf("%d", trees);
}
