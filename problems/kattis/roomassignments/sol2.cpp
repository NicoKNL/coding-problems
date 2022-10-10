#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int rooms;
    cin >> rooms;

    vector<int> room_claims(rooms + 1);

    for (int i = 1; i <= rooms - 1; ++i)
    {
        int a, b;
        cin >> a >> b;

        ++room_claims[a];
        ++room_claims[b];
    }

    vector<int> room_value(rooms + 1);

    for (int i = 1; i <= rooms; ++i)
        cin >> room_value[i];

    int unpicked_rooms = count(room_claims.begin() + 1, room_claims.end(), 0);

    cout << unpicked_rooms << endl;

    if (unpicked_rooms >= 2)
        cout << "impossible" << endl;
    else if (unpicked_rooms == 1)
    {
        // pick best value room that is not the unpicked room
        int unclaimed = -1;

        for (int i = 1; i <= rooms; ++i)
            if (room_claims[i] == 1)
                unclaimed = i;

        int best_alt_room = -1;
        int best_alt_room_value = -1;

        for (int i = 1; i <= rooms; ++i)
        {
            if (i == unclaimed)
                continue;

            if (room_value[i] > best_alt_room_value)
            {
                best_alt_room = i;
                best_alt_room_value = room_value[i];
            }
        }

        cout << "1: " << min(unclaimed, best_alt_room) << " " << max(unclaimed, best_alt_room) << endl;
    }
    else
    {
        // pick the two rooms that have only been picked once
        vector<int> singles;
        for (int i = 1; i <= rooms; ++i)
            if (room_claims[i] == 1)
                singles.push_back(i);

        sort(singles.begin(), singles.end());

        cout << "0: " << singles[0] << " " << singles[1] << endl;
    }
}

int main()
{
    int c;
    cin >> c;

    while (c--)
    {
        cout << "---------------------------" << endl;
        solve();
    }
    return 0;
}