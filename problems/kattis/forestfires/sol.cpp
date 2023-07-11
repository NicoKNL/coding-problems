#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int seed;
vector<vector<int>> grid;

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

void nextSeed()
{
    seed = (seed * 5171 + 13297) % 50021;
}

pair<int, int> indexToXY(int index)
{
    int r = index / 100;
    int c = index % 100;
    return {r, c};
}

bool hasTree(int index)
{
    auto [r, c] = indexToXY(index);
    return grid[r][c] == 1;
}

void connectAdjacents(UnionFind &UF, int index)
{
    auto [r1, c1] = indexToXY(index);
    vector<int> offsets = {-100, -1, 1, 100};
    for (int offset : offsets)
    {
        int adj = index + offset;
        if (adj >= 0 && adj < 100 * 100)
        {
            auto [r2, c2] = indexToXY(adj);
            int dr = abs(r1 - r2);
            int dc = abs(c1 - c2);

            if (dr + dc <= 3)
                if (grid[r2][c2] == 1)
                    UF.unionSet(index, adj);
        }
    }
}

int placeTree(UnionFind &UF)
{
    while (true)
    {
        nextSeed();
        int treeIndex = seed % 10000;
        auto [r, c] = indexToXY(treeIndex);

        if (grid[r][c] == 0)
        {
            grid[r][c] = 1;
            connectAdjacents(UF, treeIndex);
            return treeIndex;
        }
    }
}

int getTree(int i)
{
    nextSeed();
    return seed % (i + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    while (cin >> seed >> n)
    {
        grid = vector<vector<int>>(100, vector<int>(100, 0));
        vector<int> trees(n, 0);
        UnionFind UF(100 * 100);

        int i = 0;
        int count = 0;
        while (i < n)
        {
            trees[i] = placeTree(UF);
            int A = trees[getTree(i)];
            int B = trees[getTree(i)];

            if (UF.isSameSet(A, B))
                count++;

            if (i % 100 == 99)
            {
                cout << count << " ";
                count = 0;
            }
            i++;
        }
        cout << endl;
    }
}
