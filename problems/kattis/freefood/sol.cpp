#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> V(366, 0);

    for (int i = 0; i < n; ++i)
    {
        int from, to;
        cin >> from >> to;
        ++V[from];
        --V[to + 1];
    }

    int count = 0;
    int events = 0;
    for (int i = 0; i < V.size(); ++i)
    {
        events += V[i];
        if (events)
            ++count;
    }

    cout << count << endl;

    return 0;
}