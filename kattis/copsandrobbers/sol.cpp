#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int from;
    int to;
    double length;

    Edge(int f, int t, double l) : from(f), to(t), length(l) {}
};

struct Node
{
    vector<int> out;
};

struct Graph
{
    vector<Node> nodes;
    vector<Edge> edges;

    Graph(int nr_nodes, int nr_edges)
    {
        nodes.resize(nr_nodes);
        edges.reserve(nr_edges);
    }

    void add_edge(int from, int to, double length)
    {
        Edge e = Edge(from, to, length);
        edges.push_back(e);
        nodes[from].out.push_back(edges.size() - 1);
    }

    void print_all()
    {
        for (int i = 0; i < nodes.size(); ++i)
        {
            Node n = nodes[i];
            cout << "Node " << i << " has edges to: ";
            for (int ii = 0; ii < n.out.size(); ++ii)
            {
                cout << edges[n.out[ii]].to << " ";
            }
            cout << endl;
        }
    }
};

vector<int> find_augmenting_path(const Graph &graph, int source, int sink, vector<double> flow, double *path_cap)
{
    set<pair<double, int>, greater<pair<double, int>>> Q;
    vector<double> capacity(graph.nodes.size(), 0);
    vector<int> pred(graph.nodes.size(), -1);
    vector<int> path;

    capacity[source] = INT32_MAX;
    Q.insert(make_pair(INT32_MAX, source));

    while ((!Q.empty()) && (capacity[sink] == 0))
    {
        double cap = Q.begin()->first;
        const Node &node = graph.nodes[Q.begin()->second];
        Q.erase(Q.begin());
        for (auto e_idx : node.out)
        {
            const Edge &e = graph.edges[e_idx];
            double e_cap = e.length - flow[e_idx];
            if ((e_cap > 0) &&
                (min(cap, e_cap) > capacity[e.to]))
            {
                Q.erase(make_pair(capacity[e.to], e.to));
                capacity[e.to] = min(cap, e_cap);
                Q.insert(make_pair(capacity[e.to], e.to));
                pred[e.to] = e_idx;
            }
        }
    }

    /* Reconstruct the path */
    *path_cap = capacity[sink];
    {
        int e_idx = pred[sink];
        while (e_idx != -1)
        {
            path.push_back(e_idx);
            e_idx = pred[graph.edges[e_idx].from];
        }
    }
    return path;
}

double max_flow(const Graph &graph, int source, int sink)
{
    Graph residual(graph.nodes.size(),
                   2 * graph.edges.size());
    vector<double> flow(2 * graph.edges.size(), 0);
    vector<int> path;
    double path_cap;
    double max_flow = 0;

    for (const auto &edge : graph.edges)
    {
        residual.add_edge(edge.from, edge.to, edge.length);
        residual.add_edge(edge.to, edge.from, 0);
    }
    path = find_augmenting_path(residual, source, sink, flow,
                                &path_cap);
    while (path_cap > 0)
    {
        for (auto e_idx : path)
        {
            int e_ridx = e_idx + 1;
            if ((e_idx % 2) == 1)
                e_ridx = e_idx - 1;
            flow[e_idx] = flow[e_idx] + path_cap;
            flow[e_ridx] = flow[e_ridx] - path_cap;
        }
        path = find_augmenting_path(residual, source, sink,
                                    flow, &path_cap);
    }
    for (auto e_idx : residual.nodes[source].out)
    {
        max_flow = max_flow + flow[e_idx];
    }

    return max_flow;
}

int get_cost(const vector<vector<char>> &grid, const vector<int> &costs, int r, int c)
{
    if (grid[r][c] == '.')
        return INT32_MAX;

    if (grid[r][c] == 'B')
        return -1;

    return costs[grid[r][c] - 'a'];
}

int main()
{
    // Parse inputs
    int ncols, nrows, ncosts;
    cin >> ncols >> nrows >> ncosts;

    vector<vector<char>> raw_grid(nrows, vector<char>(ncols, '.'));
    for (int r = 0; r < nrows; ++r)
        for (int c = 0; c < ncols; ++c)
            cin >> raw_grid[r][c];

    vector<int> costs(ncosts);
    for (int i = 0; i < ncosts; ++i)
        cin >> costs[i];

    // Construct graph
    int nr_of_nodes = nrows * ncols + 1; // +1 for sink
    Graph graph(nr_of_nodes, 0);
    int source;
    int sink = nrows * ncols;
    for (int r = 0; r < nrows; ++r)
    {
        for (int c = 0; c < ncols; ++c)
        {
            int from = r * ncols + c;

            if (raw_grid[r][c] == 'B')
                source = from;

            int to, cost;

            if (r == 0 || c == 0 || r == nrows - 1 || c == ncols - 1)
            {
                // Connect to sink
                to = ncols * nrows;
                cost = INT32_MAX;
                graph.add_edge(from, sink, cost);
            }

            if (r > 0)
            {
                to = (r - 1) * ncols + c;
                cost = get_cost(raw_grid, costs, r - 1, c);

                if (cost > 0)
                    graph.add_edge(from, to, cost);
            }

            if (r < nrows - 1)
            {
                to = (r + 1) * ncols + c;
                cost = get_cost(raw_grid, costs, r + 1, c);
                if (cost > 0)
                    graph.add_edge(from, to, cost);
            }

            if (c > 0)
            {
                to = r * ncols + c - 1;
                cost = get_cost(raw_grid, costs, r, c - 1);
                if (cost > 0)
                    graph.add_edge(from, to, cost);
            }

            if (c < ncols - 1)
            {
                to = r * ncols + c + 1;
                cost = get_cost(raw_grid, costs, r, c + 1);
                if (cost > 0)
                    graph.add_edge(from, to, cost);
            }
        }
    }

    // Perform max flow - min cut
    unsigned long long flow = max_flow(graph, source, sink);
    if (flow > 2000000000 || flow < 0)
        cout << -1 << endl;
    else
        cout << flow << endl;

    return 0;
}