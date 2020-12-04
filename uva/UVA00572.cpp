#include<bits/stdc++.h>
using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<int, int> ii;
#define loop(i, n) for (int i = 0; i < n; i++)

vector<ii> adj(int r, int c, int rows, int cols) {
    vector<ii> adj;
    if (r > 0) adj.push_back({r-1, c});
    if (c > 0) adj.push_back({r, c-1});
    if (r < rows - 1) adj.push_back({r+1, c});
    if (c < cols - 1) adj.push_back({r, c+1});

    // diagonals
    if (r > 0 && c > 0) adj.push_back({r-1, c-1});
    if (r > 0 && c < cols - 1) adj.push_back({r-1, c+1});
    if (r < rows - 1 && c > 0) adj.push_back({r+1, c-1});
    if (r < rows - 1 && c < cols - 1) adj.push_back({r+1, c+1});
    return adj;
}

int main() {
    int rows, cols;
    while (cin >> rows >> cols) {
        if (rows == 0 && cols == 0) break;
        vvc grid(rows, vc(cols, '*'));
        vvc visited(rows, vc(cols, 'n'));
        loop(r, rows) loop(c, cols) cin >> grid[r][c];

        int count = 0;
        loop(r, rows) loop(c, cols) {
            if (visited[r][c] == 'y') continue;
            if (grid[r][c] == '*') continue;
            count++;
            queue<ii> Q;
            Q.push({r, c});
            visited[r][c] = 'y';

            while (!Q.empty()) {
                ii current = Q.front(); Q.pop();
                int sr = current.first, sc = current.second;
                for (ii target : adj(sr, sc, rows, cols)) {
                    int tr = target.first, tc = target.second;
                    if (visited[tr][tc] == 'y') continue;
                    visited[tr][tc] = 'y';
                    if (grid[tr][tc] == '@') Q.push({tr, tc});
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}