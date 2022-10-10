#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, p, s;
    cin >> n >> p >> s;

    for (int i = 0; i < s; ++i)
    {
        int m;
        cin >> m;
        bool is_in_set = false;
        for (int ii = 0; ii < m; ++ii)
        {
            int c;
            cin >> c;

            if (c == p)
                is_in_set = true;
        }

        if (is_in_set)
        {
            cout << "KEEP" << endl;
        }
        else
        {
            cout << "REMOVE" << endl;
        }
    }

    return 0;
}