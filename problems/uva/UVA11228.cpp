#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

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

struct City {
    int x, y;
};

int main() {
    int n;
    cin >> n;
    int cases = 1;
    while (n--) {
        int V, r;
        cin >> V >> r;

        vector<City> cities(V);

        loop(i, V) {
            cin >> cities[i].x >> cities[i].y;
        }

        vector<pair<int, ii>> edges;
        UnionFind states(V);
        loop(s, V) {
            City a = cities[s];
            loop(t, V) {
                if (s == t) continue;
                City b = cities[t];
                if (pow(a.x - b.x, 2) + pow(a.y - b.y, 2) <= pow(r, 2)) {
                    states.unionSet(s, t);
                }
                edges.push_back({pow(a.x - b.x, 2) + pow(a.y - b.y, 2), {s, t}});
            }
        }

        sort(edges.begin(), edges.end());
        vi mst_edges;
        double roads = 0, rails = 0;
        UnionFind UF(V);
        loop(i, edges.size()) {
            pair<int, ii> front = edges[i];
            if (!UF.isSameSet(front.second.first, front.second.second)) {
                if (front.first <= pow(r, 2)) roads += sqrt(front.first);
                else rails += sqrt(front.first);
                mst_edges.push_back(front.first);
                UF.unionSet(front.second.first, front.second.second);
            }
        }

        int state_count = states.numDisjointSets();
        printf("Case #%d: %d %d %d\n", cases, state_count, (int) round(roads), (int) round(rails));
        cases++;
    }
    return 0;
}