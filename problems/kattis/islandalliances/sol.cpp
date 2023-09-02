#include <iostream>
#include <vector>
#include <utility>
#include <vector>
#include <unordered_set>

using namespace std;

struct UnionFind
{
    vector<int> p, rank; // p = parent, rank = speedup

    UnionFind(int N) : p(N, -1), rank(N, 0) {}

    int find(int i) { return p[i] == -1 ? i : p[i] = find(p[i]); }

    void unite(int i, int j)
    {
        int x = find(i), y = find(j);

        if (rank[x] > rank[y]) // keep x 'shorter' than y for speed
            swap(x, y);
        p[x] = y;

        if (rank[x] == rank[y])
            rank[y]++; // optional speedup
    }
};

int main()
{
    int islands, distrust_count, proposal_count;
    cin >> islands >> distrust_count >> proposal_count;

    UnionFind states(islands + 1);
    vector<unordered_set<int>> distrusts(islands + 1);

    while (distrust_count--)
    {
        int a, b;
        cin >> a >> b;
        distrusts[a].insert(b);
        distrusts[b].insert(a);
    }

    while (proposal_count--)
    {
        int a, b;
        cin >> a >> b;
        a = states.find(a);
        b = states.find(b);

        if (distrusts[a].find(b) != distrusts[a].end())
        {
            cout << "REFUSE" << endl;
            continue;
        }

        cout << "APPROVE" << endl;
        states.unite(a, b);
        int root = states.find(a);

        if (root != a)
        {
            distrusts[root].insert(distrusts[a].begin(), distrusts[a].end());
            for (auto each : distrusts[a])
            {
                distrusts[each].erase(a);
                distrusts[each].insert(root);
            }
            distrusts[a] = {};
        }

        if (root != b)
        {
            distrusts[root].insert(distrusts[b].begin(), distrusts[b].end());
            for (auto each : distrusts[b])
            {
                distrusts[each].erase(b);
                distrusts[each].insert(root);
            }
            distrusts[b] = {};
        }
    }
}