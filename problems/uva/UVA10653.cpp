#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

enum {
    SAFE,
    UNSAFE,
    VISITED
};

struct Pos {
    int r, c;
};
int rows, cols;

bool inBounds(const int & r, const int & c) {
    return (0 <= r && r < rows) && (0 <= c && c < cols);
}

vector<Pos> neighbours(const Pos & u) {
    vector<Pos> adj;
    if (inBounds(u.r + 1, u.c)) adj.push_back({u.r + 1, u.c});
    if (inBounds(u.r, u.c + 1)) adj.push_back({u.r, u.c + 1});
    if (inBounds(u.r - 1, u.c)) adj.push_back({u.r - 1, u.c});
    if (inBounds(u.r, u.c - 1)) adj.push_back({u.r, u.c - 1});
    return adj;
}


int main() {
    while (cin >> rows >> cols) {
        if (rows == 0 && cols == 0) break;

        vvi grid(rows, vi(cols, SAFE));
        vvi dist(rows, vi(cols, 0));
        int bombrows; cin >> bombrows;
        loop(i, bombrows) {
            int r, bombs, c;
            cin >> r >> bombs;
            while (bombs--) {
                cin >> c;
                grid[r][c] = UNSAFE;
            }
        }
        Pos s, t;
        cin >> s.r >> s.c >> t.r >> t.c;

        queue<Pos> Q;
        Q.push(s);
        grid[s.r][s.c] = VISITED;

        while (!Q.empty()) {
            Pos u = Q.front();
            Q.pop();
            vector<Pos> adj = neighbours(u);
            for (Pos v : adj) {
                if (grid[v.r][v.c] == SAFE) {
                    Q.push(v);
                    grid[v.r][v.c] = VISITED;
                    dist[v.r][v.c] = dist[u.r][u.c] + 1;
                }
            }
        }

        printf("%d\n", dist[t.r][t.c]);
    }


    return 0;
}