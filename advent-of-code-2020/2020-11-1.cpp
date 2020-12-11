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

int occupiedSeatCount(int row, int col) 
{
    vector<int> rows = {row - 1, row, row + 1};
    vector<int> cols = {col - 1, col, col + 1};

    int count = 0;
    for (int r : rows) {
        if (r < 0 || r >= grid.size()) continue;
        for (int c : cols) {
            if (c < 0 || c >= grid[0].size() || (c == col && r == row)) continue;
            if (grid[r][c] == '#') ++count;
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
                if (grid[r][c] == '#' && count >= 4) {
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
