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

    vector<pair<int, int>> offsets = {
        {1, 1},
        {3, 1},
        {5, 1},
        {7, 1},
        {1, 2}
    };

    long long total_trees = 1;

    for (pair<int, int> offset : offsets) {
        int offset_x = offset.first;
        int offset_y = offset.second;
        int trees = 0; 

        int x = 0;
        int y = 0;

        while (y < grid.size()) {
            if (grid[y][x] == '#') ++trees;
            x = (x + offset_x) % grid[0].size();
            y += offset_y;
        }
        printf("%d\n", trees);
        total_trees *= (long long) trees;
    }

    printf("%lld", total_trees);
}
