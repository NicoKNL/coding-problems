#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int i = 0;
    unsigned long long value = 0;
    int height = 0;
    bool visited = false;
    Node *to = nullptr;
    vector<Node *> from;
};

ostream &operator<<(ostream &os, const unordered_set<Node *> &nodes)
{
    for (const Node *u : nodes)
    {
        os << u->value << ", " << u->height << endl;
    }
    return os;
}

void computeHeight(Node *u, int height)
{
    u->height = height;

    for (Node *v : u->from)
        computeHeight(v, height + 1);
}

vector<Node *> constructGraph(int n)
{
    vector<Node *> nodes;

    nodes.push_back(new Node);
    nodes[0]->value = 0;

    for (int i = 1; i <= n; ++i)
    {
        Node *u = new Node;
        cin >> u->value;
        u->i = i;
        nodes.push_back(u);
    }

    for (int u = 1; u <= n; ++u)
    {
        int v;
        cin >> v;
        nodes[u]->to = nodes[v];
        nodes[v]->from.push_back(nodes[u]);
    }

    computeHeight(nodes[0], 0);

    return nodes;
}

unordered_set<Node *> getTriggers(vector<Node *> &nodes)
{
    unordered_set<Node *> triggers;

    for (Node *u : nodes)
        if (u->from.size() == 0)
            triggers.insert(u);

    return triggers;
}

// {max, total}
int DEPTH = 0;
pair<unsigned long long, unsigned long long> getPathCost(Node *u)
{
    // cout << "-------------------------------------------" << endl;
    // for (int i = 0; i < DEPTH; ++i)
    //     cout << "|   ";
    // cout << "visiting: " << u->i << " " << u->value << " " << u->height << endl;
    if (u->visited)
        return {0, 0};

    auto result = make_pair<>(u->value, u->value);
    auto result_before = result;
    // for (int i = 0; i < DEPTH; ++i)
    //     cout << "|   ";
    // cout << "result: " << result.first << " " << result.second << endl;

    if (u->to == nullptr)
        return result;

    // ++DEPTH;
    auto to_result = getPathCost(u->to);
    // --DEPTH;
    // for (int i = 0; i < DEPTH; ++i)
    //     cout << "|   ";
    // cout << "to result: " << to_result.first << " " << to_result.second << endl;
    result.first = max(result.first, to_result.first);
    result.second += to_result.second;
    // for (int i = 0; i < DEPTH; ++i)
    //     cout << "|   ";
    // cout << "best: " << result_before.first << " vs " << result.first << endl;
    // for (int i = 0; i < DEPTH; ++i)
    //     cout << "|   ";
    // cout << "sum:  " << result_before.second << " vs " << result.second << endl;

    return result;
}

void visit(Node *u)
{
    if (u->visited)
        return;

    u->visited = true;

    if (u->to == nullptr)
        return;

    visit(u->to);
}

unsigned long long solve()
{
    int n;
    cin >> n;

    vector<Node *> nodes = constructGraph(n);
    unordered_set<Node *> triggers = getTriggers(nodes);

    unsigned long long result = 0;
    // cout << triggers << endl;

    while (triggers.size())
    {
        unsigned long long min_cost = numeric_limits<unsigned long long>::max();
        unsigned long long gain;
        Node *min_node = nullptr;
        for (Node *u : triggers)
        {
            // {max, total}
            pair<unsigned long long, unsigned long long> path_cost = getPathCost(u);
            // cout << u->i << " " << path_cost.first << " " << path_cost.second << endl;
            // exit(0);
            if (path_cost.second - path_cost.first < min_cost)
            {
                min_cost = path_cost.second - path_cost.first;
                gain = path_cost.first;
                min_node = u;
            }
        }
        cout << ".." << endl;
        cout << min_node->i << ": " << min_cost << " and " << gain << endl;
        cout << ".." << endl;
        result += gain;
        visit(min_node);
        triggers.erase(min_node);
    }

    return result;
}

int main()
{
    int T;
    cin >> T;

    for (int i = 1; i <= T; ++i)
        cout << "Case #" << i << ": " << solve() << endl;

    return 0;
}