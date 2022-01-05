#include <bits/stdc++.h>

using namespace std;

void flood(const vector<vector<char>> &G, vector<vector<int>> &GID, int r, int c, int id)
{
    vector<int> ro = {0, 0, -1, 1};
    vector<int> co = {-1, 1, 0, 0};

    queue<pair<int, int>> Q;
    Q.push({r, c});
    GID[r][c] = id;

    while (!Q.empty())
    {
        r = Q.front().first;
        c = Q.front().second;
        Q.pop();

        for (int i = 0; i < ro.size(); ++i)
        {
            int _r = r + ro[i];
            int _c = c + co[i];

            if (0 <= _r && _r < G.size() && 0 <= _c && _c < G[0].size())
            {
                if (G[_r][_c] == '-' && GID[_r][_c] == 0)
                {
                    GID[_r][_c] = id;
                    Q.push({_r, _c});
                }
            }
        }
    }
}

int main()
{
    int nrows, ncols;
    int t = 1;
    while (cin >> nrows >> ncols)
    {
        vector<vector<char>> G(nrows, vector<char>(ncols, '#'));
        vector<vector<int>> GID(nrows, vector<int>(ncols, 0));

        for (int r = 0; r < nrows; ++r)
            for (int c = 0; c < ncols; ++c)
                cin >> G[r][c];

        int id = 1;
        for (int r = 0; r < nrows; ++r)
            for (int c = 0; c < ncols; ++c)
                if (G[r][c] == '-' && GID[r][c] == 0)
                    flood(G, GID, r, c, id++);

        printf("Case %d: %d\n", t, id - 1);
        ++t;
    }

    return 0;
}