#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;
struct Edge
{                  /* Directed edge */
    int from;      /* Index of the source node */
    int to;        /* Index of the destination node */
    double length; /* Length of the edge */
    int value;
    Edge(int f, int t, double v)
        : from(f), to(t), length(1), value(v) {}
};

struct Node
{
    vector<int> out; /* Indices of edges that start in this node */
};

struct Graph
{                       /* Directed graph */
    vector<Node> nodes; /* List of nodes */
    vector<Edge> edges; /* List of edges */

    Graph(int nr_nodes, int nr_edges)
    {
        nodes.resize(nr_nodes);  /* Create  */
        edges.reserve(nr_edges); /* Reserve  */
    }

    Edge &add_edge(int from, int to, double length)
    {
        Edge e = Edge(from, to, length);
        edges.push_back(e); /* Add edge to the list */
        nodes[from].out.push_back(edges.size() -
                                  1); /* Add to the node */
        return *edges.end();
    }

    void print_all()
    {
        for (unsigned int i = 0; i < nodes.size(); i++)
        {
            Node n = nodes[i];
            cout << "Node " << i << " has edges to: ";
            for (unsigned int j = 0; j < n.out.size(); ++j)
            {
                cout << "(" << edges[n.out[j]].to << ": " << edges[n.out[j]].length << ") ";
            }
            cout << endl;
        }
    }
};

bool DinicBFS(const Graph &graph, const int s, const int t,
              const vector<double> &flow,
              vector<int> &level)
// Check if more flow can be sent from s to t, and assign a
// level to each node.
{
    for (size_t i = 0; i < graph.nodes.size(); i++)
        level[i] = -1;
    level[s] = 0;

    // BFS, following edges that can still have extra flow
    list<int> q;
    q.push_back(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop_front();
        for (int edge_idx : graph.nodes[u].out)
        {
            const Edge &e = graph.edges[edge_idx];
            if ((level[e.to] < 0) &&
                (flow[edge_idx] < e.length))
            {
                // Level = level of parent + 1
                level[e.to] = level[e.from] + 1;
                q.push_back(e.to);
            }
        }
    }

    // If sink was not reached then no more flow can be sent
    return level[t] < 0 ? false : true;
}

int DinicSendFlow(const Graph &graph, const int u,
                  const double flow_to_send, const int sink,
                  vector<double> &flow,
                  const vector<int> &level,
                  vector<size_t> &start)
/* Send flow (using DFS) from a node to the sink,
 * given a currently existing flow and a level assignment
 * done by DinicBFS
 * The start parameter is used to ensure a different path is
 * used on subsequent calls */
{
    cout << u << " ";
    // Stop if end is reached or no flow is being sent
    if ((u == sink) || (flow_to_send == 0))
        return flow_to_send;

    // Traverse all edges of the node (starting at a place
    // that wasn't used last time).
    for (; start[u] < graph.nodes[u].out.size(); start[u]++)
    {
        const int edge_idx = graph.nodes[u].out[start[u]];
        const Edge &e = graph.edges[edge_idx];

        if ((level[e.to] == level[e.from] + 1) &&
            (flow[edge_idx] < e.length))
        {
            int flow_that_can_be_sent =
                min(flow_to_send, e.length - flow[edge_idx]);
            int flow_that_was_sent =
                DinicSendFlow(graph, e.to, flow_that_can_be_sent,
                              sink, flow, level, start);
            if (flow_that_was_sent > 0)
            {
                // Update edge and its reverse
                flow[edge_idx] += flow_that_was_sent;
                int reverse_edge_idx = edge_idx ^ 1;
                flow[reverse_edge_idx] -= flow_that_was_sent;
                return flow_that_was_sent;
            }
        }
    }

    return 0;
}

pair<double, vector<double>>
DinicMaxFlow(const Graph &graph, const int s, const int t)
/* Returns maximum flow in graph using Dinic's algorithm
 * Complexity is:
 * O(V^2 * E) in the general case,
 * O(E*min(V**(2/3), sqrt(E))) when all edges have unit
 * capacity,
 * O(E*sqrt(V)) when all edges have unit capacities and (one
 * incoming or one outgoing edge)
 * The latter case occurs when doing maximum cardinality
 * matching on a bipartite graph, in which case this
 * algorithm is known as the Hopcroft-Karp algorithm
 */
{
    assert(s != t);

    /* Construct residual graph */
    Graph residual(graph.nodes.size(),
                   2 * graph.edges.size());

    for (const auto &edge : graph.edges)
    {
        residual.add_edge(edge.from, edge.to, edge.length);
        residual.add_edge(edge.to, edge.from, 0);
    }

    double max_flow = 0;
    vector<double> flow(residual.edges.size(), 0);
    vector<int> level(residual.nodes.size());
    vector<size_t> start(residual.nodes.size());

    // Augment flow as long as possible
    while (DinicBFS(residual, s, t, flow, level))
    {
        // But don't use the same path in subsequent
        // DinicSendFlow calls
        fill(start.begin(), start.end(), 0);
        cout << endl;
        while (int added_flow = DinicSendFlow(
                   residual, s, INT_MAX, t, flow, level, start))
        {
            max_flow += added_flow;
            cout << endl
                 << "updated flow: " << max_flow << endl;
        }
    }

    // Determine flows for each edge in the original graph
    vector<double> flow_result(graph.edges.size());
    for (size_t i = 0; i < flow.size(); i += 2)
        flow_result[i / 2] = flow[i];

    // Return maximum flow
    return make_pair(max_flow, flow_result);
}

int main()
{
    int n, m, r;
    cin >> n >> m >> r;

    vector<pair<int, pair<int, int>>> input;
    Graph g(n + m + 2, r + n + m);
    for (int i = 0; i < r; ++i)
    {
        int u, v, value;
        cin >> u >> v >> value;
        input.push_back({value, {u, v}});
    }

    sort(input.begin(), input.end(), std::greater<pair<int, pair<int, int>>>());

    // SOURCE = 0
    // SINK   = n + m + 1
    for (auto &each : input)
    {
        int u, v, value;
        value = each.first;
        u = each.second.first;
        v = each.second.second;
        const Edge &edge = g.add_edge(u, n + v, value);
    }

    // hook up source
    for (int i = 0; i < n; ++i)
        g.add_edge(0, i + 1, 0);

    // hook up sink
    for (int i = 0; i < m; ++i)
        g.add_edge(n + i + 1, n + m + 1, 0);

    g.print_all();
    cout << "to: " << n + m + 1 << endl;
    pair<double, vector<double>> result = DinicMaxFlow(g, 0, n + m + 1);
    for (auto each : result.second)
        cout << each << " ";
    cout << endl;
    cout << "flow: " << result.first << endl;
    int unmatched = n - static_cast<int>(result.first);
    cout << unmatched << endl;

    int answer = 0;
    for (int i = 0; i < r; ++i)
        answer += result.second[i];

    cout << answer << endl;
}
