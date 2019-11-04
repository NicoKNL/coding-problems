#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<char> vc;
typedef vector<vc> vvc;

#define loop(i, n) for (int i = 0; i < n; i++)

vii adj(int r, int c, int rows, int cols) {
    vii result;
    if (r > 0) result.push_back({r-1, c});
    if (c > 0) result.push_back({r, c-1});
    if (r != rows - 1) result.push_back({r+1, c});
    if (c != cols - 1) result.push_back({r, c+1});
    return result;
}

int main() {
    int n;
    cin >> n;
    int cases = 1;
    while (n--) {
        int rows, cols;
        cin >> rows;
        cols = rows;

        vvc grid(rows, vc (cols));
        vector<vector<bool>> visited(rows, vector<bool> (cols));

        string srow;
        loop(r, rows) {
            cin >> srow;
            loop(c, cols) {
                grid[r][c] = srow[c];
            }
        }

        int count = 0;
        loop(r, rows) loop(c, cols) {
            if (!visited[r][c] && (grid[r][c] == '@' || grid[r][c] == 'x')) {
                bool found = false;
                queue<ii> Q;
                Q.push({r, c});
                visited[r][c] = true;
                while (!Q.empty()) {
                    ii cell = Q.front(); Q.pop();
                    if (!found && grid[cell.first][cell.second] == 'x') {
                        found = true;
                        count++;
                    }
                    vii neighbours = adj(cell.first, cell.second, rows, cols);
                    loop(i, neighbours.size()) {
                        ii t_cell = neighbours[i];
                        if (!visited[t_cell.first][t_cell.second] && (grid[t_cell.first][t_cell.second] == '@' || grid[t_cell.first][t_cell.second] == 'x')) {
                            visited[t_cell.first][t_cell.second] = true;
                            Q.push(t_cell);
                        }
                    }
                }
            }
        }
        printf("Case %d: %d\n", cases, count);
        cases++;
    }
    return 0;
}