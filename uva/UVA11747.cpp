#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class UnionFind {
private:
    vi p, rank;
public:
    UnionFind(int N) {
        p.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i;
        rank.assign(N, 0);
    }

    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);

        if (rank[x] > rank[y]) swap(x, y);
        p[x] = y;

        if (rank[x] == rank[y]) rank[y]++;
    }
};

struct Edge {
    int start, end;
    int cost;
};

bool CompEdge (Edge & i, Edge & j) {
    return i.cost < j.cost;
}

vi Kruskal(vector<Edge> & E, int V, vector<Edge> & mst) {
    UnionFind uf(V);
    sort(E.begin(), E.end(), CompEdge);

    vi max_cost;
    for (int i = 0; i < E.size(); i++) {
        int s = E[i].start;
        int t = E[i].end;
        if (uf.findSet(s) != uf.findSet(t)) {
            uf.unionSet(s, t);
            mst.push_back(E[i]);
        } else {
            max_cost.push_back(E[i].cost);
        }
    }

    return max_cost;
}

int main() {
    int V, E;
    while (cin >> V >> E) {
        if (V == 0 && E == 0) break;

        vector<Edge> edges(E);
        for (int i = 0; i < E; i++) {
            cin >> edges[i].start >> edges[i].end >> edges[i].cost;
        }
        vector<Edge> mst;
        vi heaviest = Kruskal(edges, V, mst);

        if (heaviest.empty()) {
            printf("forest\n");
        } else {
            sort(heaviest.begin(), heaviest.end());
            for (int i = 0; i < heaviest.size(); i++) {
                if (i > 0) cout << " ";
                cout << heaviest[i];
            }
            cout << endl;
        }
    }
    return 0;
}