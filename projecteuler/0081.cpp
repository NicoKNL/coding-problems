#include <bits/stdc++.h>
using namespace std;

int main()
{
    // grab input file
    ifstream infile("../projecteuler/input/p081_matrix.txt");
    if (!infile.is_open()) {
        return -1;
    }

    // parse input file into vvi grid
    vector<vector<int>> grid;
    string line = "";
    while (getline(infile, line)) {
        stringstream ss(line);
        int value;
        vector<int> row;
        while (ss >> value) {
            row.push_back(value);
            if (ss.peek() == ',') ss.ignore();
        }
        grid.push_back(row);
    }

    // Iteratively push values down path from topleft to bottom right
    for (int i = 1; i < 2 * grid.size(); ++i) {
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid.size(); ++col) {
                if (row + col != i) {
                    continue;
                } else if (row == 0 && col == 0) {
                    continue;
                } else if (row == 0) {
                    grid[row][col] += grid[row][col - 1];
                } else if (col == 0) {
                    grid[row][col] += grid[row - 1][col];
                } else { // (row > 0 && col > 0)
                    int v = grid[row][col];
                    grid[row][col] = min(v + grid[row-1][col], v + grid[row][col - 1]);
                }
            }
        }
    }
    cout << grid[grid.size() - 1][grid.size() - 1];
}
