#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> V(n, 0);

        for (int i = 0; i < n; ++i)
        {
            cin >> V[i];
        }

        sort(V.begin(), V.end());

        int dist = (V.back() - V.front()) * 2;

        cout << dist << endl;
    }

    return 0;
}