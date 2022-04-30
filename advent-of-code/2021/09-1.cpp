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

int riskAt(const vector<vector<int>> &height_map, int r, int c)
{
    int center = height_map[r][c];

    vector<pair<int, int>> offsets = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (const auto &o : offsets)
    {
        if ((0 <= c + o.first) && (c + o.first < height_map[0].size()) && (0 <= r + o.second) && (r + o.second < height_map.size()))
        {
            if (center >= height_map[r + o.second][c + o.first])
                return 0;
        }
    }
    return center + 1;
}

int riskLevelSum(const vector<vector<int>> &height_map)
{
    int risk = 0;
    for (int r = 0; r < height_map.size(); ++r)
    {
        for (int c = 0; c < height_map[0].size(); ++c)
        {
            risk += riskAt(height_map, r, c);
        }
    }
    return risk;
}

int main()
{
    string s;

    vector<vector<int>> height_map;
    while (getline(cin, s))
    {
        if (s.length() == 0)
            break;

        vector<int> row;
        for (const char &c : s)
        {
            row.push_back(c - '0');
        }

        height_map.push_back(row);
    }

    cout << height_map << endl;
    cout << riskLevelSum(height_map) << endl;

    return 0;
}