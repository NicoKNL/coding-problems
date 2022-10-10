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
    int cost;
};

bool CompEdge (Edge & i, Edge & j) {
    return i.cost < j.cost;
}

int main() {
    int C, S, Q;
    int cases = 1;
    while (cin >> C >> S >> Q) {
        if (C == 0 && S == 0 && Q == 0) break;
        if (cases >> 1) cout << endl;
        cout << "Case #" << cases << endl;
        // construct edges
        vector<Edge> E(S);
        loop(i, S) cin >> E[i].start >> E[i].end >> E[i].cost;

        vector<Edge> mst;

        /* begin kruskal */
        UnionFind uf(C + 1);
        sort(E.begin(), E.end(), CompEdge);

        for (int i = 0; i < E.size(); i++) {
            int s = E[i].start;
            int t = E[i].end;
            if (uf.findSet(s) != uf.findSet(t)) {
                uf.unionSet(s, t);
                mst.push_back(E[i]);
            }
        }
        /* end kruskal */

        int u, v;
        vi visited(C + 1);
        vi cost(C + 1);
        vector<vii> adj(C + 1);
        loop(i, mst.size()) {
            u = mst[i].start;
            v = mst[i].end;
            adj[u].push_back({v, mst[i].cost});
            adj[v].push_back({u, mst[i].cost});
        }

        int s , t;
        loop(i, Q) {
            cin >> s >> t;
            if (!uf.isSameSet(s, t)) {
                cout << "no path" << endl;
                continue;
            }
            visited.assign(C + 1, 0);
            cost.assign(C + 1, 0);

            queue<int> Q;
            Q.push(s); visited[s] = 1;
            while (!Q.empty() && !visited[t]) {
                u = Q.front(); Q.pop();
                for (ii edge : adj[u]) {
                    v = edge.first;
                    if (!visited[v]) {
                        visited[v] = true;
                        cost[v] = max(cost[u], edge.second);
                        Q.push(v);
                    }
                    if (v == t) break;
                }
            }
            cout << cost[t] << endl;
        }

        cases++;
    }
    return 0;
}