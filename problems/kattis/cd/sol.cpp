#include <bits/stdc++.h>

using namespace std;

int main()
{
    while (true)
    {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        unordered_map<unsigned long long, bool> M;

        for (int i = 0; i < n; ++i)
        {
            unsigned long long cd;
            cin >> cd;
            M[cd] = true;
        }

        int count = 0;

        for (int i = 0; i < m; ++i)
        {
            unsigned long long cd;
            cin >> cd;
            if (M.find(cd) != M.end())
                ++count;
        }
        cout << count << endl;
    }
    return 0;
}