#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

#define loop(i, n) for (int i = 0; i < n; i++)

class UnionFind {
private:
    vector<int> p, rank, setSize;// vi p is the key part
    int numSets;
public:
    UnionFind(int N) {
        p.assign(N, 0);
        for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0);    // optional speedup
        setSize.assign(N, 1); // optional feature
        numSets = N;              // optional feature
    }

    int findSet(int i) {
        return (p[i] == i) ?
               i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    // 2x optional
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return; // same set already
        int x = findSet(i), y = findSet(j);

        // keep x 'shorter' than y and set x under y
        if (rank[x] > rank[y]) swap(x, y);
        p[x] = y;

        if (rank[x] == rank[y]) rank[y]++; // optional speedup
        setSize[y] += setSize[x]; // combine set sizes at y
        numSets--;                // a union reduces numSets
    }
};

int main() {
    int V, E;
    while (cin >> V >> E) {
        if (V == 0 && E == 0) break;
        vector<pair<int, ii>> edges;
        int w, s, t;
        int total_cost = 0;
        loop(i, E) {
            cin >> s >> t >> w;
            edges.push_back(make_pair(w, ii(s, t)));
            total_cost += w;
        }
        sort(edges.begin(), edges.end());
        int mst_cost = 0;
        UnionFind UF(V);
        loop(i, E) {
            pair<int, ii> front = edges[i];
            if (!UF.isSameSet(front.second.first, front.second.second)) {
                mst_cost += front.first;
                UF.unionSet(front.second.first, front.second.second);
            }
        }
        cout << total_cost - mst_cost << endl;
    }
    return 0;
}