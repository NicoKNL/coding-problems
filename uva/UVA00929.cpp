#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vi> vvi;
typedef vector<ii> vii;

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
    while (n--) {
        int rows, cols;
        cin >> rows >> cols;

        vvi grid(rows, vi (cols));
        vvi cost(rows, vi(cols));
        loop(r, rows) loop(c, cols) {
            cin >> grid[r][c];
            cost[r][c] = INT_MAX;
        }

        priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> PQ;
        PQ.push({grid[0][0], {0, 0}});
        cost[0][0] = grid[0][0];

        while (!PQ.empty()) {
            ii cell = PQ.top().second;
            int dist = PQ.top().first;
            PQ.pop();
            vii neighbours = adj(cell.first, cell.second, rows, cols);
            loop(i, neighbours.size()) {
                ii t_cell = neighbours[i];
                int t_dist = grid[t_cell.first][t_cell.second];
                if (dist + t_dist < cost[t_cell.first][t_cell.second]) {
                    cost[t_cell.first][t_cell.second] = dist + t_dist;
                    PQ.push({cost[t_cell.first][t_cell.second], {t_cell.first, t_cell.second}});
                }
            }
        }
        cout << cost[rows-1][cols-1] << endl;
    }
    return 0;
}