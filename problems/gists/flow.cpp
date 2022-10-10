#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int MAX_V = 1010;
vvi residual;
int max_flow, flow, s, t;
vi parent;

// assumes s, t, and residual are initialized
void read_graph() { // opt arg for bipartite: int h, int v
}

void augment(int v, int min_edge) {
    if (v == s) {
        flow = min_edge;
        return;
    } else if (parent[v] != -1) {
        augment(parent[v], min(min_edge, residual[parent[v]][v]));
        residual[parent[v]][v] -= flow;
        residual[v][parent[v]] += flow;
    }
}

int main()
{
    int n_cases;
    cin >> n_cases;
    while (n_cases--) {
        int h, v; // Number of horizontal, and vertical words
        cin >> h >> v;

        residual = vector<vector<int>> (MAX_V, vector<int>(MAX_V));
        s = h + v;
        t = h + v + 1;

        read_graph(h, v); // construct initial capacity values etc

        max_flow = 0;
        while (true) {
            flow = 0;
            vi dist(MAX_V, INT_MAX); dist[s] = 0;
            queue<int> Q; Q.push(s);
            parent.assign(MAX_V, -1);
            while (!Q.empty()) {
                int u = Q.front(); Q.pop();
                if (u == t) break; // reached sink
                for (int v = 0; v < MAX_V; v++) {
                    if (residual[u][v] > 0 && dist[v] == INT_MAX) {
                        dist[v] = dist[u] + 1;
                        Q.push(v);
                        parent[v] = u;
                    }
                }
            }
            augment(t, INT_MAX);
            if (flow == 0) break;
            max_flow += flow;
        }
        printf("%d\n", h + v - max_flow);
    }
    return 0;
}