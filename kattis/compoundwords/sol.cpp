#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> V;

    string s;
    while (cin >> s)
        V.push_back(s);

    set<string> S;

    for (int i = 0; i < V.size(); ++i)
    {
        for (int ii = 0; ii < V.size(); ++ii)
        {
            if (i == ii)
                continue;

            S.insert(V[i] + V[ii]);
        }
    }

    for (string each : S)
        cout << each << endl;

    return 0;
}