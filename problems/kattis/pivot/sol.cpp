#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> V(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> V[i];

    vector<int> left_max(n, 0);
    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
            left_max[i] = V[i];
        else
            left_max[i] = max(left_max[i - 1], V[i]);
    }

    vector<int> right_min(n, 0);
    for (int i = n - 1; i >= 0; --i)
    {
        if (i == n - 1)
            right_min[i] = V[i];
        else
            right_min[i] = min(right_min[i + 1], V[i]);
    }

    int pivots = 0;
    for (int i = 0; i < n; ++i)
    {
        bool left_OK = false;
        bool right_OK = false;

        if (i == 0)
            left_OK = true;
        else if (left_max[i - 1] <= V[i])
            left_OK = true;

        if (i == n - 1)
            right_OK = true;
        else if (right_min[i + 1] > V[i])
            right_OK = true;

        if (left_OK && right_OK)
        {
            ++pivots;
        }
    }

    cout << pivots << endl;

    return 0;
}