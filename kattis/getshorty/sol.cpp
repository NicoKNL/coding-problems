#include <bits/stdc++.h>

using namespace std;

int main()
{
    fixed(cout);
    cout.precision(4);

    while (true)
    {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        vector<vector<pair<int, double>>> V(n);
        vector<double> size(n, -INFINITY);

        while (m--)
        {
            int s, t;
            double w;

            cin >> s >> t >> w;

            V[s].push_back({t, w});
            V[t].push_back({s, w});
        }

        size[0] = 1.0;

        priority_queue<pair<double, int>> Q;
        Q.push({size[0], 0});

        while (!Q.empty())
        {
            double usize = Q.top().first;
            int u = Q.top().second;
            Q.pop();

            if (u == n - 1)
                break;

            for (auto adj : V[u])
            {
                int t = adj.first;
                double factor = adj.second;

                if (usize * factor > size[t])
                {
                    size[t] = usize * factor;
                    Q.push({size[t], t});
                }
            }
        }

        cout << size[n - 1] << endl;
    }

    return 0;
}