#include <bits/stdc++.h>

using namespace std;

ostream &operator<<(ostream &os, const vector<vector<int>> &V)
{
    for (int r = 0; r < V.size(); ++r)
    {
        for (int c = 0; c < V[0].size(); ++c)
        {
            os << V[r][c] << " ";
        }
        os << endl;
    }
    return os;
}

int floodFill(const vector<vector<int>> &height_map, vector<vector<int>> &visited, int r, int c)
{
    queue<pair<int, int>> Q;
    Q.push({r, c});
    visited[r][c] = 1;

    int poolsize = 0;
    while (!Q.empty())
    {
        pair<int, int> pos = Q.front();
        Q.pop();

        r = pos.first;
        c = pos.second;

        ++poolsize;

        vector<pair<int, int>> offsets = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (const auto &o : offsets)
        {
            if ((0 <= c + o.first) && (c + o.first < height_map[0].size()) && (0 <= r + o.second) && (r + o.second < height_map.size()))
            {
                if (height_map[r + o.second][c + o.first] < 9 && !visited[r + o.second][c + o.first])
                {
                    visited[r + o.second][c + o.first] = 1;
                    Q.push({r + o.second, c + o.first});
                }
            }
        }
    }

    return poolsize;
}

vector<int> getPools(const vector<vector<int>> &height_map, vector<vector<int>> &visited)
{
    vector<int> pools;

    for (int r = 0; r < height_map.size(); ++r)
    {
        for (int c = 0; c < height_map[0].size(); ++c)
        {
            if (!visited[r][c] && height_map[r][c] < 9)
                pools.push_back(floodFill(height_map, visited, r, c));
        }
    }

    return pools;
}

int main()
{
    string s;

    vector<vector<int>> height_map;
    vector<vector<int>> visited;
    while (getline(cin, s))
    {
        if (s.length() == 0)
            break;

        vector<int> row;
        vector<int> row_visited;
        for (const char &c : s)
        {
            row.push_back(c - '0');
            row_visited.push_back(0);
        }

        height_map.push_back(row);
        visited.push_back(row_visited);
    }

    cout << height_map << endl;
    vector<int> pools = getPools(height_map, visited);
    sort(pools.begin(), pools.end());
    reverse(pools.begin(), pools.end());

    int result = pools[0] * pools[1] * pools[2];

    cout << visited << endl;

    cout << result << endl;
    return 0;
}