#include <iostream>
#include <vector>

using namespace std;

struct UnionFind
{
    vector<int> p, rank; // vi p is the key part

    UnionFind(int N)
    {
        p.assign(N, 0);
        for (int i = 0; i < N; ++i)
            p[i] = i;
        rank.assign(N, 0); // optional speedup
    }

    int findSet(int i)
    {
        return p[i] == i ? i : p[i] = findSet(p[i]);
    }

    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j)
    {
        int x = findSet(i), y = findSet(j);

        if (x == y)
            return;

        // keep x 'shorter' than y and set x under y
        if (rank[x] > rank[y])
            swap(x, y);
        p[x] = y;

        if (rank[x] == rank[y])
            rank[y]++; // optional speedup
    }
};

int main()
{
    ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    UnionFind UF(N);

    while (Q--)
    {
        char q;
        int a, b;
        cin >> q >> a >> b;
        if (q == '?')
        {
            if (UF.isSameSet(a, b))
                cout << "yes\n";
            else
                cout << "no\n";
        }
        else
        {
            UF.unionSet(a, b);
        }
    }
}