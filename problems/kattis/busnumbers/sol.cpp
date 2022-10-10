#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> V(n, 0);

    for (int i = 0; i < n; ++i)
        cin >> V[i];

    sort(V.begin(), V.end());

    vector<pair<int, int>> ranges;

    bool tracking = false;
    int lo = -1;
    for (int i = 0; i < n; ++i)
    {
        if (!tracking)
        {
            tracking = true;
            lo = V[i];
        }
        else
        {
            if (V[i] - V[i - 1] != 1)
            {
                tracking = false;
                i -= 1;
                ranges.push_back({lo, V[i]});
            }
        }
    }

    ranges.push_back({lo, *V.rbegin()});

    for (int i = 0; i < ranges.size(); ++i)
    {
        if (i > 0)
            cout << " ";

        pair<int, int> range = ranges[i];

        if (range.first == range.second)
            cout << range.first;
        else if (range.first + 1 == range.second)
            cout << range.first << " " << range.second;
        else
            cout << range.first << "-" << range.second;
    }

    cout << endl;

    return 0;
}