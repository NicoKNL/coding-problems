#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int target;
    int w;

};

struct Vertex {
    vector<Edge> adj;
    int dist = INT_MAX;
    bool visited = false;
    int parent = -1;
};

struct Best {
    int current = -1;
    int next = -1;
    double dist = -1;
};

int main() {
    int cases = 1;
    while (true) {
        int V, E;
        cin >> V >> E;
        if (V == 0 && E == 0) break;
        vector<Vertex> G(V + 1);

        if (cases > 1) cout << endl;

        int s, t, dist;
        for (int i = 0; i < E; i++) {
            cin >> s >> t >> dist;
            G[s].adj.push_back({t, dist});
            G[t].adj.push_back({s, dist});
        }

        priority_queue<pair<int, int>,
                vector<pair<int, int>>,
                greater<pair<int, int>>> PQ;
        G[1].dist = 0;
        PQ.push(make_pair(0, 1));
        while(!PQ.empty()) {
            int id = PQ.top().second;
            int dist = PQ.top().first;
            PQ.pop();
            for (Edge edge : G[id].adj) {
                if (dist + edge.w < G[edge.target].dist) {
                    G[edge.target].dist = dist + edge.w;
                    PQ.push(make_pair(G[edge.target].dist, edge.target));
                    G[edge.target].parent = id;
                }
            }
        }

        int best_a = -1, best_b = -1;
        double best_seconds = -1, seconds;
        for (int a = 1; a < G.size(); a++) {
            if (G[a].dist > best_seconds) {
                best_seconds = G[a].dist;
                best_a = a;
                best_b = -1;
            }
            for (Edge e : G[a].adj) {
                int b = e.target;
                if (a == b) continue;
                if (a == G[b].parent || b == G[a].parent) continue;
                if (G[a].dist + e.w == G[b].dist) continue;
                seconds = (G[a].dist + G[b].dist + e.w) / 2.0;
                if (seconds > best_seconds) {
                    best_b = b;
                    best_seconds = seconds;
                }
            }
        }

        cout << "System #" << cases << endl;
        if (best_b == -1) {
            cout << "The last domino falls after " << fixed << setprecision(1) << best_seconds << " seconds, at key domino " << best_a << "." << endl;
        } else {
            cout << "The last domino falls after " << fixed << setprecision(1) << best_seconds << " seconds, between key dominoes " << min(best_a, best_b) << " and " << max(best_a, best_b)  << "." << endl;
        }
        cases++;
    }
    return 0;
}