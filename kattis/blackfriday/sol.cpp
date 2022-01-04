#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<int, int> M;
    vector<pair<int, int>> V;
    for (int i = 1; i <= n; ++i)
    {
        int roll;
        cin >> roll;
        ++M[roll];
        V.push_back({roll, i});
    }

    sort(V.begin(), V.end(), greater<pair<int, int>>());

    for (auto each : V)
    {
        if (M[each.first] == 1)
        {
            cout << each.second << endl;
            return 0;
        }
    }

    cout << "none" << endl;

    return 0;
}