#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid(101, vector<int>(101));
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

int main() 
{
    // grab input file
    ifstream infile ("../advent-of-code-2020/input/24.txt");
    if (!infile.is_open()) {
        return -1;
    }


    while (getline(infile, line)) {
        row = 50;
        col = 50;
        while (line.length() > 0) {
            extractMove();
            visit();
        }
        grid[row][col] = 1 - grid[row][col]; 
    }

    int count = 0;
    for (int r = 0; r < 101; ++r) {
        for (int c = 0; c < 101; ++c) {
            count += grid[r][c];
        }
    }
    cout << count << endl;
}
