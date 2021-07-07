#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

enum {
    UNVISITED,
    EVEN,
    ODD,
    WATER
};
int rows, cols, x, y;
vvi grid;
struct Pos {
    int x, y;
};

bool inBounds(int r, int c) {
    return (0 <= r && r < rows) && (0 <= c && c < cols);
}

vector<Pos> adj(int r, int c) {
    set<ii> result;
    if (inBounds(r+x, c+y)) result.insert({r+x, c+y});
    if (inBounds(r+x, c-y)) result.insert({r+x, c-y});
    if (inBounds(r-x, c+y)) result.insert({r-x, c+y});
    if (inBounds(r-x, c-y)) result.insert({r-x, c-y});

    if (inBounds(r+y, c+x)) result.insert({r+y, c+x});
    if (inBounds(r+y, c-x)) result.insert({r+y, c-x});
    if (inBounds(r-y, c+x)) result.insert({r-y, c+x});
    if (inBounds(r-y, c-x)) result.insert({r-y, c-x});

    vector<Pos> adj;
    for (auto entry : result) {
        adj.push_back({entry.first, entry.second});
    }
    return adj;
}

bool countVisit(int r, int c) {
    int count = 0;
    for (Pos a : adj(r, c)) {
        if (grid[a.x][a.y] != WATER) count++;
    }

    if (count & 1) {
        grid[r][c] = ODD;
        return false;
    } else {
        grid[r][c] = EVEN;
        return true;
    }
}

int main() {
    int n;
    cin >> n;
    for (int t = 1; t <= n; t++) {
        cin >> rows >> cols >> x >> y;

        grid.assign(rows, vi(cols, UNVISITED));

        int water; cin >> water;
        int r, c;
        loop(w, water) {
            cin >> r >> c;
            grid[r][c] = WATER;
        }

        int even = 0, odd = 0;

        queue<Pos> Q;
        Q.push({0, 0});
        if (countVisit(0, 0)) {
            even++;
        } else {
            odd++;
        }

        while (!Q.empty()) {
            Pos u = Q.front(); Q.pop();
            for (Pos v : adj(u.x, u.y)) {
                if (grid[v.x][v.y] == UNVISITED) {
                    Q.push(v);
                    if (countVisit(v.x, v.y)) {
                        even++;
                    } else {
                        odd++;
                    }
                }
            }
        }

        printf("Case %d: %d %d\n", t, even, odd);
    }
    return 0;
}