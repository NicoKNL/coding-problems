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
    result.push_back({r, (c-1+cols)%cols});
    if (r != rows - 1) result.push_back({r+1, c});
    result.push_back({r, (c+1)%cols});
    return result;
}

int main() {
    int rows, cols;
    while (cin >> rows >> cols) {

        vvc grid(rows, vc (cols));
        vector<vector<bool>> visited(rows, vector<bool> (cols));

        string srow;
        loop(r, rows) {
            cin >> srow;
            loop(c, cols) {
                grid[r][c] = srow[c];
            }
        }

        int R, C;
        cin >> R >> C;
        char L = grid[R][C];
        vector<int> sizes;
        int count;
        loop(r, rows) loop(c, cols) {
            if (!visited[r][c] && grid[r][c] == L) {
                bool own_continent = false;
                count = 1;
                queue<ii> Q;
                Q.push({r, c});
                visited[r][c] = true;
                while (!Q.empty()) {
                    ii cell = Q.front(); Q.pop();
                    if (cell.first == R && cell.second == C) own_continent = true;
                    vii neighbours = adj(cell.first, cell.second, rows, cols);
                    loop(i, neighbours.size()) {
                        ii t_cell = neighbours[i];
                        if (!visited[t_cell.first][t_cell.second] && grid[t_cell.first][t_cell.second] == L) {
                            visited[t_cell.first][t_cell.second] = true;
                            count++;
                            Q.push(t_cell);
                        }
                    }
                }
                if (!own_continent) sizes.push_back(count);
            }
        }

        if (sizes.empty()) {
            printf("0\n");
        } else {
            sort(sizes.begin(), sizes.end(), greater<int>());
            printf("%d\n", sizes[0]);
        }
    }
    return 0;
}