#include <bits/stdc++.h>

using namespace std;

ostream &operator<<(ostream &os, vector<vector<int>> &V)
{
    for (int r = 0; r < V.size(); ++r)
    {

        for (int c = 0; c < V[0].size(); ++c)
        {
            os << V[r][c];
        }
        os << endl;
    }
    return os;
}

vector<pair<int, int>> adj(int r, int c, int nrows, int ncols)
{
    vector<pair<int, int>> offsets = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1},
    };

    vector<pair<int, int>> adj;

    int ro, co;
    for (auto offset : offsets)
    {
        ro = r + offset.first;
        co = c + offset.second;

        if (0 <= ro && ro < nrows && 0 <= co && co < ncols)
            adj.push_back({ro, co});
    }

    return adj;
}

void bfsFloodFill(vector<vector<int>> &G, vector<vector<int>> &id, int r, int c, int cid)
{
    int nrows = G.size();
    int ncols = G[0].size();
    int target = G[r][c];

    queue<pair<int, int>> Q;
    Q.push({r, c});

    while (!Q.empty())
    {
        tie(r, c) = Q.front();
        Q.pop();

        id[r][c] = cid;

        for (auto each : adj(r, c, nrows, ncols))
        {
            int ro, co;
            tie(ro, co) = each;
            if (G[ro][co] == target && id[ro][co] == 0)
                Q.push({ro, co});
        }
    }
}

int main()
{
    int nrows, ncols;
    cin >> nrows >> ncols;

    vector<vector<int>> G(nrows, vector<int>(ncols, 0));
    vector<vector<int>> id(nrows, vector<int>(ncols, 0));

    for (int r = 0; r < nrows; ++r)
    {
        string s;
        cin >> s;
        for (int c = 0; c < ncols; ++c)
        {
            G[r][c] = s[c] - '0';
        }
    }

    int current_id = 1;

    for (int r = 0; r < nrows; ++r)
        for (int c = 0; c < ncols; ++c)
            if (id[r][c] == 0)
                bfsFloodFill(G, id, r, c, current_id++);

    cout << id << endl;
    int queries;
    cin >> queries;

    while (queries--)
    {
        int r1, c1;
        int r2, c2;

        cin >> r1 >> c1 >> r2 >> c2;
        --r1;
        --c1;
        --r2;
        --c2;

        if (G[r1][c1] != G[r2][c2] || id[r1][c1] != id[r2][c2])
            cout << "neither" << endl;
        else if (G[r1][c1] == 0)
            cout << "binary" << endl;
        else
            cout << "decimal" << endl;
    }

    return 0;
}