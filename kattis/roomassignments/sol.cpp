#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int rooms;
    cin >> rooms;

    //
    // PARSE ROOM CHOICES
    //
    vector<int> room_claims(rooms + 1);
    vector<vector<int>> adj(rooms + 1);

    for (int i = 1; i <= rooms - 1; ++i)
    {
        int a, b;
        cin >> a >> b;

        ++room_claims[a];
        ++room_claims[b];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //
    // PARSE ROOM VALUES
    //
    vector<int> room_value(rooms + 1);

    for (int i = 1; i <= rooms; ++i)
        cin >> room_value[i];

    //
    // EVALUATE ROOM CHOICE CONNECTIVITY VIA FLOODFILL
    //
    vector<bool> visited(rooms + 1, false);
    vector<int> ids(rooms + 1);

    int id = 0;
    for (int i = 1; i <= rooms; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            ids[i] = id;

            queue<int> Q;
            Q.push(i);

            while (!Q.empty())
            {
                int u = Q.front();
                Q.pop();

                for (int v : adj[u])
                {
                    if (!visited[v])
                    {
                        visited[v] = true;
                        ids[v] = id;
                        Q.push(v);
                    }
                }
            }

            ++id;
        }
    }

    //
    // VALIDATE IF GROUPSIZES SUPPORT CHOICE COUNTS
    //
    vector<int> group_room_sizes(id);
    vector<int> group_choice_count(id);

    for (int i = 1; i <= rooms; ++i)
    {
        ++group_room_sizes[ids[i]];
        group_choice_count[ids[i]] += adj[i].size();
    }

    for (int &each : group_choice_count)
        each /= 2;

    bool possible = true;
    for (int i = 0; i < id; ++i)
    {
        if (group_room_sizes[i] < group_choice_count[i])
        {
            possible = false;
            break;
        }
    }

    if (!possible)
    {
        cout << "impossible" << endl;
        return;
    }

    //
    // MAKE OPTIMAL ASSIGNMENT
    //
    // 1 - least selected
    // 2 - highest value which is not the least selected
    int min_size = INT32_MAX;
    int min_room = -1;
    int min_size_count = 0;

    for (int i = 1; i <= rooms; ++i)
    {
        if (adj[i].size() < min_size)
        {
            min_size = adj[i].size();
            min_room = i;
            min_size_count = 1;
        }
        else if (adj[i].size() == min_size)
        {
            ++min_size_count;
        }
    }

    if (min_size_count == 2)
    {
        vector<int> choices;
        for (int i = 1; i <= rooms; ++i)
        {
            if (adj[i].size() == min_size)
            {
                choices.push_back(i);
            }
        }

        sort(choices.begin(), choices.end());

        cout << choices[0] << " " << choices[1] << endl;
        return;
    }

    if (min_size_count == 1)
    {
        if (min_room == 1)
        {
            cout << 1 << " " << 2 << endl;
        }
        else
        {
            cout << 1 << " " << min_room << endl;
        }
        return;
    }
}

int main()
{
    int c;
    cin >> c;

    while (c--)
    {
        solve();
    }
    return 0;
}