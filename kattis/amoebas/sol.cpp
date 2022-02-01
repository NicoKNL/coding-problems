#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> adj =
    {
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, -1},
        {0, 1},
        {1, -1},
        {1, 0},
        {1, 1},
};

void flood(const vector<vector<char>> &V, vector<vector<int>> &ID, int r, int c, int id)
{
    queue<pair<int, int>> Q;
    Q.push({r, c});
    ID[r][c] = id;

    while (!Q.empty())
    {
        auto [r, c] = Q.front();
        Q.pop();

        for (const auto &[ro, co] : adj)
        {
            r += ro;
            c += co;

            if (0 <= r && r < V.size() && 0 <= c && c < V[0].size())
            {
                if (V[r][c] == '#' && ID[r][c] == -1)
                {
                    ID[r][c] = id;
                    Q.push({r, c});
                }
            }

            r -= ro;
            c -= co;
        }
    }
}

int main()
{
    int nrows, ncols;
    cin >> nrows >> ncols;

    vector<vector<char>> V(nrows, vector<char>(ncols, '.'));

    for (int r = 0; r < nrows; ++r)
        for (int c = 0; c < ncols; ++c)
            cin >> V[r][c];

    vector<vector<int>> ID(nrows, vector<int>(ncols, -1));
    int id = 0;
    for (int r = 0; r < nrows; ++r)
        for (int c = 0; c < ncols; ++c)
            if (V[r][c] == '#' && ID[r][c] == -1)
                flood(V, ID, r, c, id++);

    cout << id << endl;

    return 0;
}