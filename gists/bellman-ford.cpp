#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

struct Vertex {
    vector<pair<int, int>> adj; // target, edge-lengt
    long dist = INT_MAX;
    int parent = -1;
};

vector<Vertex> V;

void BellmanFord(int source) {
    V[source].dist = 0;
    for (int j = 0; j <= V.size(); j++) {
        for (int v = 0; v < V.size(); v++) {
            for (pair<int, int> edge : V[v].adj) {
                long new_dist = V[v].dist + edge.second;
                if (new_dist < V[edge.first].dist) {
                    if (j == V.size()) { // N-th iteration, but we can still relax!
                        cout << "negative-weight cycle" << endl;
                        return;
                    }
                    V[edge.first].dist = V[v].dist + edge.second;
                    V[edge.first].parent = v;
                }
            }
        }
    }
}


int main() {
    Vertex v0, v1, v2, v3, v4, v5, v6, v7, v8;
//    v0.adj.emplace_back(1);

    v1.adj.emplace_back(make_pair(2, 1));
    v1.adj.emplace_back(make_pair(0, 1));

    v2.adj.emplace_back(make_pair(5, 1));
    v2.adj.emplace_back(make_pair(6, 1));
    v2.adj.emplace_back(make_pair(3, 1));

    v3.adj.emplace_back(make_pair(7, 1));
    v3.adj.emplace_back(make_pair(4, 1));

    v4.adj.emplace_back(make_pair(3, 1));
    v4.adj.emplace_back(make_pair(8, -1));

    v5.adj.emplace_back(make_pair(1, 1));
    v5.adj.emplace_back(make_pair(6, 1));

    v6.adj.emplace_back(make_pair(7, 1));

    v7.adj.emplace_back(make_pair(6, 1));

    v8.adj.emplace_back(make_pair(4, -1));
    v8.adj.emplace_back(make_pair(7, 1));

    V.push_back(v0);
    V.push_back(v1);
    V.push_back(v2);
    V.push_back(v3);
    V.push_back(v4);
    V.push_back(v5);
    V.push_back(v6);
    V.push_back(v7);
    V.push_back(v8);

    BellmanFord(1);
    cout << "success" << endl;
    return 0;
}