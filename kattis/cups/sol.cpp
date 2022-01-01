#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<double, string>> V(n, {0, ""});

    for (int i = 0; i < n; ++i)
    {
        string a, b;
        cin >> a >> b;
        if ('a' <= a[0] && a[0] <= 'z')
        {
            V[i].second = a;
            V[i].first = stod(b);
        }
        else
        {
            V[i].second = b;
            V[i].first = stod(a) / 2.0;
        }
    }

    sort(V.begin(), V.end());

    for (auto each : V)
        cout << each.second << endl;

    return 0;
}