#include <bits/stdc++.h>

using namespace std;

unsigned long long RESULT;

struct Node
{
    unsigned long long value = 0;
    vector<Node *> adj;
};

vector<Node *> constructGraph(int n)
{
    vector<Node *> nodes;

    nodes.push_back(new Node);
    nodes[0]->value = 0;

    for (int i = 1; i <= n; ++i)
    {
        Node *u = new Node;
        cin >> u->value;
        nodes.push_back(u);
    }

    for (int u = 1; u <= n; ++u)
    {
        int v;
        cin >> v;
        nodes[v]->adj.push_back(nodes[u]);
    }

    return nodes;
}

unsigned long long dfs(Node *u)
{
    if (u->adj.size() == 0)
        return u->value;

    vector<unsigned long long> values;

    for (Node *v : u->adj)
        values.push_back(dfs(v));

    sort(values.begin(), values.end());

    if (u->value > values[0])
        values[0] = u->value;

    if (values.size() >= 2)
        if (values[0] > values[1])
            swap(values[0], values[1]);

    unsigned long long fixed = accumulate(next(values.begin()), values.end(), 0ull);
    RESULT += fixed;
    return values[0];
}

unsigned long long solve()
{
    int n;
    cin >> n;

    vector<Node *> nodes = constructGraph(n);

    RESULT = 0;
    for (Node *u : nodes[0]->adj)
    {
        RESULT += dfs(u);
    }

    return RESULT;
}

int main()
{
    int T;
    cin >> T;

    for (int i = 1; i <= T; ++i)
        cout << "Case #" << i << ": " << solve() << endl;

    return 0;
}