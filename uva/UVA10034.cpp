#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

class UnionFind {
private:
    vi p, rank, setSize;
    int numSets;
public:
    UnionFind(int N) {
        p.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i;
        rank.assign(N, 0);
        setSize.assign(N, 1);
        numSets = N;
    }

    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    int numDisjointSets() {return numSets;}
    int sizeOfSet(int i) { return setSize[findSet(i)];}
    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);

        if (rank[x] > rank[y]) swap(x, y);
        p[x] = y;

        if (rank[x] == rank[y]) rank[y]++;
        setSize[y] += setSize[x];
        numSets--;
    }
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
        if (uf.findSet(s) != uf.findSet(t)) {
            uf.unionSet(s, t);
            mst.push_back(E[i]);
        }
    }
}

double dist(pair<double, double> a, pair<double, double> b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        int V;
        cin >>  V;
        vector<pair<double, double>> positions(V);
        loop(i, V) cin >> positions[i].first >> positions[i].second;

        // construct edges
        vector<Edge> E;
        for (int u = 0; u < V; u++) {
            for (int v = u + 1; v < V; v++) {
                E.push_back({u, v, dist(positions[u], positions[v])});
            }
        }

        vector<Edge> mst;
        Kruskal(E, V, mst);

        double total_dist = 0;
        for (Edge e : mst) {
            total_dist += e.cost;
        }

        cout << fixed << setprecision(2) << total_dist << endl;
        if (cases != 0) cout << endl;
    }
    return 0;
}