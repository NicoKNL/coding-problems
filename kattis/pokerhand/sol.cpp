#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<char, int> M;

    for (int i = 0; i < 5; ++i)
    {
        string tmp;
        cin >> tmp;

        char c = tmp[0];
        ++M[c];
    }

    int best = 0;

    for (const auto &each : M)
    {
        if (each.second > best)
        {
            best = each.second;
        }
    }

    cout << best << endl;

    return 0;
}