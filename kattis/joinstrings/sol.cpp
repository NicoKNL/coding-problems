#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<string> V(n + 1);
    vector<list<int>> IDX(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> V[i];
        IDX[i].push_back(i);
    }

    --n;

    while (n--)
    {
        int s, t;
        cin >> s >> t;

        IDX[s].splice(IDX[s].end(), IDX[t]);
    }

    for (int i = 1; i <= V.size() - 1; ++i)
        if (!IDX[i].empty())
            for (int ii : IDX[i])
                cout << V[ii];

    cout << endl;

    return 0;
}