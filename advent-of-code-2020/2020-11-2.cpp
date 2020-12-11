#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;

void printGrid()
{
    for (int r = 0; r < grid.size(); ++r) {
        for (int c = 0; c < grid[0].size(); ++c) {
            cout << grid[r][c];
        }
        cout << endl;
    }
    cout << endl << endl;
}

bool inGrid(int row, int col) 
{
    return (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size());
}

int occupiedSeatCount(int row, int col) 
{
    vector<pair<int, int>> directions = {
        {-1, 0},  // rows down
        {1, 0},   // rows up
        {0, -1},  // columns down
        {0, 1},   // columns up
        {-1, -1}, // diag 1
        {-1, 1},  // diag 2
        {1, -1},  // diag 3
        {1, 1}    // diag 4
    };

    int count = 0;
    for (pair<int, int> dir : directions) {
        int r = row + dir.first;
        int c = col + dir.second;

        while (inGrid(r, c)) {
            if (grid[r][c] == '#') {
                ++count;
                break;
            } else if (grid[r][c] == 'L') {
                break;
            } else {
                r += dir.first;
                c += dir.second;
            }
        }
    }
    return count;
}

int main() 
{
    // grab input file
    ifstream infile ("../advent-of-code-2020/input/11.txt");
    if (!infile.is_open()) {
        return -1;
    }

    string line = "";
    while (getline(infile, line)) {
        vector<char> row;
        for (char c : line) {
            row.push_back(c);
        }
        grid.push_back(row);
    }

    vector<vector<char>> next = grid;
    printGrid();
    bool change = true;
    // int i = 1;
    while (change) {
        // cout << i << endl;
        change = false;
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                int count = occupiedSeatCount(r, c);
                if (grid[r][c] == 'L' && count == 0) {
                    next[r][c] = '#';
                    change = true;
                }
                if (grid[r][c] == '#' && count >= 5) {
                    next[r][c] = 'L';
                    change = true;
                }
            }
        }
        grid = next;
        // ++i;
        // printGrid();
        // if (i == 10) change = false;
    }
    int occupied_seat_count = 0;
    for (int r = 0; r < grid.size(); ++r) {
        for (int c = 0; c < grid[0].size(); ++c) {
            if (grid[r][c] == '#') ++occupied_seat_count;
        }
    }

    cout << occupied_seat_count << endl;

    
}
