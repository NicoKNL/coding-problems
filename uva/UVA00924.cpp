#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

ii maxBoom(vi const & depth) {
    map<int, int> counter;
    for (int d : depth) {
        if (d > 0) counter[d]++;
    }

    int max_count = -1, first_day = -1;
    for (auto entry : counter) {
        if (entry.second > max_count) {
            max_count = entry.second;
            first_day = entry.first;
        }
    }

    return {max_count, first_day};
}

int main() {
    string s;
    getline(cin, s);
    stringstream ss(s);
    int E;
    ss >> E;

    vvi adj(E);
    vi visited(E, 0);
    vi depth(E, 0);
    loop(u, E) {
        getline(cin, s);
        ss.str(s); ss.clear();
        int v;
        ss >> v; // Consume first number
        while (ss >> v) {
            adj[u].push_back(v);
        }
    }

    int T;
    getline(cin, s);
    ss.str(s); ss.clear();
    ss >> T;
    while (T--) {
        getline(cin, s); ss.str(s); ss.clear();
        int su; ss >> su;
        visited.assign(E, 0);
        depth.assign(E, 0);
        queue<int> Q;
        Q.push(su);
        visited[su] = 1;

        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (int v: adj[u]) {
                if (!visited[v]) {
                    visited[v] = 1;
                    depth[v] = depth[u] + 1;
                    Q.push(v);
                }
            }
        }

        ii result = maxBoom(depth);
        if (result.first == -1 && result.second == -1) {
            printf("0\n");
        } else {
            printf("%d %d\n", result.first, result.second);
        }
    }
    return 0;
}

/*
6
2 1 2
2 3 4
3 0 4 5
1 4
0
2 0 2
3
0
4
5

 */