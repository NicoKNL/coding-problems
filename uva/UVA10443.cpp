#include <iostream>
#include <vector>
#include <string>

#define vvc vector<vector<char>>
#define vc vector<char>

using namespace std;

vc unique(vc iterable) {
    vc new_set;
    bool found;
    for (char i: iterable) {
        found = false;
        for (char s: new_set) {
            if (i == s) found = true;
        }
        if (!found) new_set.push_back(i);
    }
    return new_set;
}

char fight(char a, char b) {
    char tmp;
    if (a == b) return a;
    if (b < a) {
        tmp = a;
        a = b;
        b = tmp;
    }
    if (a == 'P' && b == 'S') return 'S';
    else if (a == 'P' && b == 'R') return 'P';
    else return 'R'; //if (a == 'R' && b == 'S')
}

vvc step(vvc grid) {
    vvc next_grid;
    char cell;
    for (int row = 0; row < grid.size(); row++) {
        vc next_row;
        vc fighters;
        for (int col = 0; col < grid[0].size(); col++) {
            fighters.clear();
            cell = grid[row][col];
            if (col - 1 >= 0)               fighters.push_back(fight(cell, grid[row][col - 1]));
            if (col + 1 < grid[row].size()) fighters.push_back(fight(cell, grid[row][col + 1]));
            if (row - 1 >= 0)               fighters.push_back(fight(cell, grid[row - 1][col]));
            if (row + 1 < grid.size())      fighters.push_back(fight(cell, grid[row + 1][col]));

            fighters = unique(fighters);
            if (fighters.size() > 1) {
                char a = fighters[0];
                char b = fighters[1];
                fighters = vc {fight(a, b)};
            }

            if (fighters.size() == 0) {
                fighters = vc {cell};
            }
            next_row.push_back(fighters[0]);
        }
        next_grid.push_back(next_row);
    }
    return next_grid;
}

int main() {
    int n, rows, cols, matches;
    string tmp;
    vvc grid;
    cin >> n;
    while (n--) {
        cin >> rows >> cols >> matches;
        grid.clear();

        if (rows == 0 || cols == 0) {
            cout << endl;
            if (n) cout << endl;
            continue;
        }

        for (int row = 0; row < rows; row++) {
            cin >> tmp;
            vc new_row;
            for (int col = 0; col < cols; col++) new_row.push_back(tmp.at(col));
            grid.push_back(new_row);
        }

        while (matches--) grid = step(grid);

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) cout << grid[row][col];
            cout << endl;
        }
        if (n) cout << endl;
    }
    return 0;
}