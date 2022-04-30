#include <bits/stdc++.h>

using namespace std;

struct Cave
{
    int cost;
    int dist;
    vector<Cave *> adj;
    Cave *prev;
    Cave(char c)
    {
        cost = c - '0';
        dist = INT32_MAX;
    }
};

int main()
{
    string line;
    vector<vector<Cave *>> caves;

    while (getline(cin, line))
    {
        if (line.length() == 0)
            break;

        stringstream ss;
        ss << line;

        vector<Cave *> row;
        char tmp;
        while (ss >> tmp)
        {
            row.push_back(new Cave(tmp));
        }
        caves.push_back(row);
    }

    for (int r = 0; r < caves.size(); ++r)
    {
        for (int c = 0; c < caves[0].size(); ++c)
        {
            if (r - 1 >= 0)
                caves[r - 1][c]->adj.push_back(caves[r][c]);
            if (c - 1 >= 0)
                caves[r][c - 1]->adj.push_back(caves[r][c]);
            if (r + 1 < caves.size())
                caves[r + 1][c]->adj.push_back(caves[r][c]);
            if (c + 1 < caves[0].size())
                caves[r][c + 1]->adj.push_back(caves[r][c]);
        }
    }

    // priority_queue<pair<int, Cave *>> PQ;
    caves[0][0]->dist = 0;
    int n = caves.size();
    for (int i = 0; i < n; ++i)
    {
        for (int r = i; r < n; ++r)
        {
            if (r == 0 && i == 0)
                continue;

            Cave *cave = caves[r][i];

            int a_dist = INT32_MAX, b_dist = INT32_MAX;
            Cave *a_cave, *b_cave;

            if (i > 0)
            {
                a_cave = caves[r][i - 1];
                a_dist = cave->dist + a_cave->cost;
            }

            b_cave = caves[r - 1][i];
            b_dist = cave->dist + b_cave->cost;

            if (a_dist < b_dist)
            {
                cave->dist = a_dist;
                cave->prev = a_cave;
            }
            else
            {
                cave->dist = b_dist;
                cave->prev = b_cave;
            }
        }

        for (int c = i; c < n; ++c)
        {
            if (c == 0 && i == 0)
                continue;

            Cave *cave = caves[i][c];

            int a_dist = INT32_MAX, b_dist = INT32_MAX;
            Cave *a_cave, *b_cave;

            if (i > 0)
            {
                a_cave = caves[i - 1][c];
                a_dist = cave->dist + a_cave->cost;
            }

            b_cave = caves[i][c - 1];
            b_dist = cave->dist + b_cave->cost;

            if (a_dist < b_dist)
            {
                cave->dist = a_dist;
                cave->prev = a_cave;
            }
            else
            {
                cave->dist = b_dist;
                cave->prev = b_cave;
            }
        }
    }

    // PQ.push({caves[0][0]->dist, caves[0][0]});

    // while (!PQ.empty())
    // {
    //     Cave *u = PQ.top().second;
    //     int cost_u = PQ.top().first;
    //     PQ.pop();

    //     for (Cave *v : u->adj)
    //     {
    //         int alt = cost_u + v->cost;

    //         if (alt < v->dist)
    //         {
    //             v->dist = alt;
    //             v->prev = u;
    //             PQ.push({v->dist, v});
    //         }
    //     }
    // }

    Cave *end = *(*caves.rbegin()).rbegin();
    cout << end->dist << endl;

    return 0;
}