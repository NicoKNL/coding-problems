#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid(501, vector<int>(501));
vector<vector<int>> next_grid(501, vector<int>(501));
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

int count(int r, int c)
{
    bool even = row % 2 == 0;
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
    ifstream infile ("../advent-of-code-2020/input/24 copy.txt");
    if (!infile.is_open()) {
        return -1;
    }


    while (getline(infile, line)) {
        row = 250;
        col = 250;
        while (line.length() > 0) {
            extractMove();
            visit();
        }
        grid[row][col] = 1 - grid[row][col]; 
    }

    for (int i = 0; i < 100; ++i) {
        next_grid = vector<vector<int>>(501, vector<int>(501)); 

        for (int r = 1; r < 500; ++r) {
            for (int c = 1; c < 500; ++c) {
                int black_count = count(r, c);
                if (grid[r][c] == 1) {
                    if (black_count == 0 || black_count > 2) {
                        next_grid[r][c] = 0;
                    } else {
                        next_grid[r][c] = 1;
                    }
                } else {
                    if (black_count == 2) {
                        next_grid[r][c] = 1;
                    }
                }
            }
        }

        grid = next_grid;
        int count = 0;
        for (int r = 0; r < 501; ++r) {
            for (int c = 0; c < 501; ++c) {
                count += grid[r][c];
            }
        }
        cout << count << endl;
    }

    int count = 0;
    for (int r = 0; r < 501; ++r) {
        for (int c = 0; c < 501; ++c) {
            count += grid[r][c];
        }
    }
    cout << count << endl;
}
