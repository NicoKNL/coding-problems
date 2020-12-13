#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vi visited;
vi reach;
vi adj;

int dfs(int u) {
    visited[u] = 1;
    int v = adj[u];
    if (!visited[v]) {
        reach[u] = 1 + dfs(v);
        visited[u] = 0;
        return reach[u];
    } else {
        visited[u] = 0;
        return 1;
    }
}

int main() {
    int n;
    cin >> n;
    int cases = 1;
    while (n--) {
        int V;
        cin >> V;
        adj.assign(V+1, 0); // 1-based indexing
        visited.assign(V+1, 0);
        reach.assign(V+1, 0);

        int s, t;
        for (int i = 0; i < V; i++) {
            cin >> s >> t;
            adj[s] = t;
        }

        int max_count = -1;
        int best_martian;
        // Eval all cycles
        for (int i = 1; i < V + 1; i++) {
            if (reach[i] == 0) {
                dfs(i);
            }

            if (reach[i] > max_count) {
                max_count = reach[i];
                best_martian = i;
            }
        }

        printf("Case %d: %d\n", cases, best_martian);
        cases++;
    }
    return 0;
}
