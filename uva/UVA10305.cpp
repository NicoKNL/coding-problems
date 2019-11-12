#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define loop(i, n) for (int i = 0; i < n; i++)

vvi adj;
vi order;
vi visited;

void dfsTopoSort(int u) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (!visited[v]) dfsTopoSort(v);
    }
    order.push_back(u);
}

int main() {
    int V, E;
    while (cin >> V >> E) {
        if (V == 0 && E == 0) break;

        adj.assign(V+1, vi());
        visited.assign(V+1, 0);
        order = vi();
        loop(i, E) {
            int s, t;
            cin >> s >> t;
            adj[s].push_back(t);
        }

        for (int u = 1; u < V+1; u++) {
            if (!visited[u]) dfsTopoSort(u);
        }

        reverse(order.begin(), order.end());

        loop(i, order.size()) {
            if (i > 0) cout << " ";
            cout << order[i];
        }
        cout << endl;
    }
    return 0;
}