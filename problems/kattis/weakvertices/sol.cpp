#include <bits/stdc++.h>

using namespace std;

bool canFindVertexTwice(const vector<vector<int>> &G, int s, int t, int depth)
{
    if (depth == 3)
    {
        return s == t;
    }

    bool found = false;
    for (int u = 0; u < G.size(); ++u)
    {
        if (G[t][u] == 1)
        {
            found = canFindVertexTwice(G, s, u, depth + 1);
            if (found)
                break;
        }
    }

    return found;
}

int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (n == -1)
            break;

        vector<vector<int>> G(n, vector<int>(n, 0));
        for (int r = 0; r < n; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                cin >> G[r][c];
            }
        }

        vector<int> not_found;
        for (int i = 0; i < n; ++i)
        {
            if (!canFindVertexTwice(G, i, i, 0))
                not_found.push_back(i);
        }

        for (int i = 0; i < not_found.size(); ++i)
        {
            if (i > 0)
                cout << " ";
            cout << not_found[i];
        }
        cout << endl;
    }
    return 0;
}