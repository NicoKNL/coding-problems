#include <bits/stdc++.h>

using namespace std;

int main()
{
    int s, t, n;
    cin >> s >> t >> n;

    vector<int> dist(n, 0);
    vector<int> travel(n, 0);
    vector<int> cycle(n, 0);

    // fill walking times to next stop
    int tmp;
    cin >> tmp; // grab first distance to initial stop
    s += tmp;

    for (int i = 0; i < n; ++i)
    {
        cin >> dist[i];
    }

    // fill time every bus ride takes
    for (int i = 0; i < n; ++i)
    {
        cin >> travel[i];
    }

    // fill time every bus comes around
    for (int i = 0; i < n; ++i)
    {
        cin >> cycle[i];
    }

    // Step through
    for (int i = 0; i < n; ++i)
    {
        // Check if we can already take the bus. If not wait until next stop.
        if (s % cycle[i] != 0)
        {
            s += (cycle[i] - (s % cycle[i]));
        }

        // Take the bus and travel
        s += travel[i];

        // Walk to next stop
        s += dist[i];
    }

    // if current time 's' is smaller or equal than target time 't', then we're good
    if (s <= t)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }

    return 0;
}