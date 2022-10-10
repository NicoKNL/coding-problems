#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int c = 1; c <= n; ++c)
    {
        unordered_map<int, int> M;

        int g;
        cin >> g;

        while (g--)
        {
            int code;
            cin >> code;
            ++M[code];
        }

        for (auto &each : M)
        {
            if (each.second == 1)
            {
                cout << "Case #" << c << ": " << each.first << endl;
                break;
            }
        }
    }

    return 0;
}