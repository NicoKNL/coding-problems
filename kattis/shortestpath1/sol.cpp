#include <bits/stdc++.h>

using namespace std;

int main()
{
    bool first = true;
    while (true)
    {

        int n_verts, n_edges, queries, u;
        cin >> n_verts >> n_edges >> queries >> u;

        if (n_verts == 0 && n_edges == 0 && queries == 0 && u == 0)
            break;

        if (!first)
            cout << endl;

        first = false;

        vector<vector<pair<int, int>>> adj(n_verts);
        vector<int> dist(n_verts, INT32_MAX);

        for (int i = 0; i < n_edges; ++i)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
        }

        dist[u] = 0;

        queue<int> Q;
        Q.push(u);

        while (!Q.empty())
        {
            u = Q.front();
            Q.pop();

            for (auto each : adj[u])
            {
                int v = each.first;
                int weight = each.second;

                if (dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    Q.push(v);
                }
            }
        }

        while (queries--)
        {
            int v;
            cin >> v;

            if (dist[v] == INT32_MAX)
                cout << "Impossible" << endl;
            else
                cout << dist[v] << endl;
        }
    }

    return 0;
}