#include <bits/stdc++.h>
using namespace std;

#define GRID_SIZE 1001
vector<vector<int>> grid(GRID_SIZE, vector<int>(GRID_SIZE));
vector<vector<int>> next_grid(GRID_SIZE, vector<int>(GRID_SIZE));
string line = "";
string dir = "";
int row;
int col;

void extractMove()
{
    if (line.length() > 1) {
        string d = line.substr(0, 2);
        if (d == "ne" || d == "nw" || d == "se" || d == "sw") {
            dir = d;
            line = line.substr(2);
        } else {
            dir = line.substr(0, 1);
            line = line.substr(1);
        }
    } else {
        dir = line;
        line = "";
    }
}

void visit()
{
    bool even = row % 2 == 0;
    if (dir == "e") {
        ++col;
    } else if (dir == "w") {
        --col;
    } else if (dir == "ne") {
        --row;
        if (even) {

        } else {
            ++col;
        }
    } else if (dir == "se") {
        ++row;
        if (even) {

        } else {
            ++col;

        }
    } else if (dir == "sw") {
        ++row;
        if (even) {
            --col;
        } else {

        }
    } else if (dir == "nw") {
        --row;
        if (even) {
            --col;
        } else {

        }
    } else {
        cout << "ERROR" << endl;
    }
}

int countAll()
{
    int count = 0;
    for (int r = 0; r < GRID_SIZE; ++r) {
        for (int c = 0; c < GRID_SIZE; ++c) {
            count += grid[r][c];
        }
    }
    return count;
}

int count(int r, int c)
{
    bool even = (r % 2 == 0);
    int result = 0;
    result += grid[r][c + 1]; // e
    result += grid[r][c - 1]; // w

    if (even) {
        result += grid[r - 1][c]; // ne
        result += grid[r + 1][c]; // se 
        result += grid[r + 1][c - 1]; // sw 
        result += grid[r - 1][c - 1]; // nw 
    } else {
        result += grid[r - 1][c + 1]; // ne
        result += grid[r + 1][c + 1]; // se 
        result += grid[r + 1][c]; // sw 
        result += grid[r - 1][c]; // nw 
    }

    return result;
}

int main() 
{
    // grab input file
    ifstream infile ("../advent-of-code-2020/input/24.txt");
    if (!infile.is_open()) {
        return -1;
    }

    while (getline(infile, line)) {
        row = GRID_SIZE / 2;
        col = GRID_SIZE / 2;
        while (line.length() > 0) {
            extractMove();
            visit();
        }
        grid[row][col] = 1 - grid[row][col]; 
    }

    for (int i = 0; i < 100; ++i) {
        next_grid = grid; 

        for (int r = 1; r < GRID_SIZE - 1; ++r) {
            for (int c = 1; c < GRID_SIZE - 1; ++c) {
                int black_count = count(r, c);
                if (grid[r][c] == 1 && (black_count == 0 || black_count > 2)) { // black
                    next_grid[r][c] = 0;
                } else if (grid[r][c] == 0 && black_count == 2) { // white
                    next_grid[r][c] = 1;
                }
            }
        }
        grid = next_grid;
    }

    cout << countAll() << endl;
}
