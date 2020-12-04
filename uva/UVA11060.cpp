#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi visited;
vi order;
vvi adj;

//void dfsTopoSort(int u) {
//    visited[u] = 1;
//    for (int v : adj[u]) {
//        if (!visited[v]) dfsTopoSort(v);
//    }
//    order.push_back(u);
//}

int main() {
    int V, E;
    int cases = 1;
    while (cin >> V) {
        string s, t;
        map<string, int> to;
        map<int, string> from;
        adj.assign(V, vi());
        order = vi();
        visited.assign(V, 0);
        vi in_degree(V, 0);
        for (int i = 0; i < V; i++) {
            cin >> s;
            to[s] = i;
            from[i] = s;
        }

        cin >> E;

        for (int i = 0; i < E; i++) {
            cin >> s >> t;
            adj[to[s]].push_back(to[t]);
            in_degree[to[t]]++;
        }

        priority_queue<int, vector<int>, greater<int>> PQ; // min PQ
        for (int u = 0; u < V; u++) {
            if (in_degree[u] == 0) PQ.push(u);
        }

        while (!PQ.empty()) {
            int u = PQ.top(); PQ.pop();
            order.push_back(u);
            for (int v : adj[u]) {
                in_degree[v]--;
                if (in_degree[v] == 0) PQ.push(v);
            }
        }

        printf("Case #%d: Dilbert should drink beverages in this order:", cases);
        for (int i : order) {
            cout << " " << from[i];
        }
        cout << "." << endl;
        cout << endl;
        cases++;
    }
    return 0;
}