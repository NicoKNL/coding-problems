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
    int n;
    cin >> n;
    while (n--) {
        int cons;
        cin >> cons;
        int i = 0;
        map<string, int> people;
        UnionFind UF(100001);
        string a, b;
        int i_a, i_b;
        while (cons--) {
            cin >> a >> b;
            if (people.find(a) == people.end()) {
                people[a] = i;
                i_a = i;
                i++;
            } else {
                i_a = people[a];
            }
            if (people.find(b) == people.end()) {
                people[b] = i;
                i_b = i;
                i++;
            } else {
                i_b = people[b];
            }
            UF.unionSet(i_a, i_b);
            cout << UF.sizeOfSet(i_a) << endl;
        }
    }
    return 0;
}