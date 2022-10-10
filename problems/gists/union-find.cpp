#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

struct Data {
    int name;
    int rank;
    int p;
};

class UnionFind {
public:
    Data S[MAX];
    UnionFind(int n) {
        for (int i = 0; i < n; i++) {
            S[i].name = i;
            S[i].p = i;
            S[i].rank = 0;
        }
    };

    int FindSet(int a) {
        int t = a;
        // traverse to roots
        while (t != S[t].p) t = S[t].p;
        while (a != S[a].p) { // path compression
            int s = a;
            a = S[a].p;
            S[s].p = t;
        }
        return t;
    };

    void Link(int a, int b) {
        if (S[a].rank > S[b].rank) {
            S[b].p = a;
        } else {
            S[a].p = b;
            if (S[a].rank == S[b].rank) {
                S[b].rank++;
            }
        }
    };

    void Union(int a, int b) {
        Link(FindSet(a), FindSet(b));
    };
};

struct Edge {
    int start, end;
    double cost;
};

bool CompEdge (Edge & i, Edge & j) {
    return i.cost < j.cost;
}

void Kruskal(vector<Edge> & E, int V, vector<Edge> & mst) {
    UnionFind uf(V);
    sort(E.begin(), E.end(), CompEdge);

    for (int i = 0; i < E.size(); i++) {
        int s = E[i].start;
        int t = E[i].end;
        if (uf.FindSet(s) != uf.FindSet(t)) {
            uf.Union(s, t);
            mst.push_back(E[i]);
        }
    }
}

int main() {
    vector<Edge> edges;
    vector<Edge> mst;

    edges.emplace_back(Edge{0, 1, 18});
    edges.emplace_back(Edge{1, 2, 15});
    edges.emplace_back(Edge{0, 2, 10});

    Kruskal(edges, 3, mst);
    cout << mst.size() << endl;
    for (int i = 0; i < mst.size(); i++) {
        cout << mst[i].cost << " ";
    }

    return 0;
}