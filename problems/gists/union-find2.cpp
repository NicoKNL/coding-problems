#include <bits/stdc++.h>

using namespace std;

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

    return 0;
}