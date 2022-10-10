#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> parseTree(int n)
{
    vector<vector<int>> adj(n, vector<int>());

    for (int i = 0; i < n - 1; ++i)
    {
        int s, t;
        cin >> s >> t;
        adj[s].push_back(t);
        adj[t].push_back(s);
    }

    return adj;
}

vector<bool> getLeafs(const vector<vector<int>> &adj)
{
    vector<bool> is_leaf(adj.size(), false);
    for (int s = 0; s < adj.size(); ++s)
        if (adj[s].size() == 1)
            is_leaf[s] = true;
    return is_leaf;
}

vector<int> getDFSOrder(const vector<vector<int>> &adj, int root)
{
    vector<int> order;
    vector<bool> visited(adj.size(), false);
    visited[root] = true;

    stack<int> S;
    S.push(root);

    while (!S.empty())
    {
        int u = S.top();
        S.pop();
        order.push_back(u);

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                S.push(v);
            }
        }
    }

    return order;
}

int main()
{
    int n, root;
    cin >> n >> root;

    vector<vector<int>> adj = parseTree(n);
    vector<bool> is_leaf = getLeafs(adj);
    vector<int> order = getDFSOrder(adj, root);

    struct Leaf
    {
        int u;
        int order;
    };

    vector<Leaf> ordered_leafs;

    for (int i = 0; i < order.size(); ++i)
    {
        int u = order[i];

        if (is_leaf[u])
            ordered_leafs.push_back({u, i});
    }

    sort(ordered_leafs.begin(), ordered_leafs.end(),
         [](const Leaf &lhs, const Leaf &rhs)
         { return lhs.order < rhs.order; });

    if (ordered_leafs.size() % 2 == 0)
    {
        cout << ordered_leafs.size() / 2 << endl;
    }
    else
    {
        cout << ordered_leafs.size() / 2 + 1 << endl;
    }

    for (int i = 0; i < ordered_leafs.size() / 2; ++i)
        cout << ordered_leafs[i].u << " " << ordered_leafs[ordered_leafs.size() / 2 + i].u << endl;

    if (ordered_leafs.size() % 2 == 1)
        cout << ordered_leafs[0].u << " " << ordered_leafs[ordered_leafs.size() - 1].u << endl;
}