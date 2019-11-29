#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int rows, cols;


ii operator+(const ii & a, const ii & b) {
    return {a.first + b.first, a.second + b.second};
}

ii turnLeft(ii dir) {
    return {-dir.second, dir.first};
}

ii turnRight(ii dir) {
    return {dir.second, -dir.first};
}

bool inBounds(ii pos, ii dir, const vvi & grid) {
    ii next_pos = pos + dir;
    return (0 <= next_pos.first && next_pos.first < rows) && (0 <= next_pos.second && next_pos.second < cols) && grid[next_pos.first][next_pos.second] == 0;
}

void printGrid(ii pos, const vvi & grid) {
    cout << "---------------------------\n";
    loop(r, rows) {
        loop(c, cols) {
            if (r == pos.first && c == pos.second) {
                cout << 'X';
            } else {
                cout << grid[r][c];
            }
        }
        cout << '\n';
    }
}

int main() {
    while (cin >> rows >> cols) {
        if (rows == 0 && cols == 0) break;

        vvi grid(rows, vi(cols));
        vvi count(rows, vi(cols, 0));

        string rowstr;
        loop(r, rows) {
            cin >> rowstr;
            loop(c, cols) {
                grid[r][c] = rowstr[c] - '0';
            }
        }

        ii base_pos = {rows - 1, 0};
        ii pos = {rows - 1, 0};
        ii dir = {0, 1};
        ii new_pos = {-1, -1};

        while (count[base_pos.first][base_pos.second] == 0) {
            if (inBounds(pos, turnRight(dir), grid)) {
                // try going right
                dir = turnRight(dir);
            } else if (inBounds(pos, dir, grid)) {
                // then try going forward
            } else {
                // otherwise turn left and restart
                dir = turnLeft(dir);
                continue;
            }
            new_pos = pos + dir;
            count[new_pos.first][new_pos.second]++;
            pos = new_pos;
//            printGrid(pos, grid);
        }

        vi book(5);

        loop(r, rows) loop(c, cols) {
            if (grid[r][c] == 0) {
                book[count[r][c]]++;
            }
        }

        loop(i, 5) {
            cout << setw(3) << book[i];
        }
        cout << '\n';
    }

    return 0;
}