#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> OFFSETS = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1},
};

void tag(const vector<vector<char>> &G, vector<vector<int>> &ID, int r, int c, int id)
{
    queue<pair<int, int>> Q;
    Q.push({r, c});
    ID[r][c] = id;

    while (!Q.empty())
    {
        auto [r, c] = Q.front();
        Q.pop();

        for (auto &[ro, co] : OFFSETS)
        {
            r += ro;
            c += co;

            if (0 <= r && r < G.size() && 0 <= c && c < G[0].size())
                if ((G[r][c] == 'L' || G[r][c] == 'C') && ID[r][c] == 0)
                {
                    ID[r][c] = id;
                    Q.push({r, c});
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

    vector<vector<char>> G(nrows, vector<char>(ncols, 'C'));

    for (int r = 0; r < nrows; ++r)
        for (int c = 0; c < ncols; ++c)
        {
            char tmp;
            cin >> tmp;
            if (tmp == 'W')
                G[r][c] = 'W';
            if (tmp == 'L')
                G[r][c] = 'L';
        }

    vector<vector<int>> ID(nrows, vector<int>(ncols, 0));
    int id = 1;

    for (int r = 0; r < nrows; ++r)
        for (int c = 0; c < ncols; ++c)
            if (G[r][c] == 'L' && ID[r][c] == 0)
                tag(G, ID, r, c, id++);

    cout << id - 1 << endl;

    return 0;
}