#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1, vector<int>());
    vector<bool> visited(n + 1, false);

    for (int i = 0; i < m; ++i)
    {
        int s, t;
        cin >> s >> t;

        adj[s].push_back(t);
        adj[t].push_back(s);
    }

    queue<int> Q;
    Q.push(1);
    visited[1] = true;

    while (!Q.empty())
    {
        int s = Q.front();
        Q.pop();

        for (int t : adj[s])
        {
            if (!visited[t])
            {
                visited[t] = 1;
                Q.push(t);
            }
        }
    }

    bool fully_connected = true;
    for (int i = 1; i <= n; ++i)
        if (!visited[i])
        {
            fully_connected = false;
            cout << i << endl;
        }

    if (fully_connected)
        cout << "Connected" << endl;

    return 0;
}