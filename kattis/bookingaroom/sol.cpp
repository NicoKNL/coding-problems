#include <bits/stdc++.h>

using namespace std;

int main()
{
    int rooms, booked;
    cin >> rooms >> booked;

    if (rooms == booked)
    {
        cout << "too late" << endl;
        return 0;
    }

    vector<int> V(rooms + 1, 0);
    for (int i = 0; i < booked; ++i)
    {
        int room;
        cin >> room;
        V[room] = 1;
    }

    for (int i = 1; i <= rooms; ++i)
    {
        if (!V[i])
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}