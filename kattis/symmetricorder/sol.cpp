#include <bits/stdc++.h>

using namespace std;

ostream &operator<<(ostream &os, vector<string> &V)
{
    for (string s : V)
    {
        os << s << endl;
    }
    return os;
}

int main()
{
    int n;
    int c = 1;
    while (cin >> n)
    {
        if (n == 0)
            break;

        vector<string> V(n, "");
        int lo = 0;
        int hi = n - 1;

        for (int i = 0; i < n; ++i)
        {
            if (i & 1)
            {
                cin >> V[hi];
                --hi;
            }
            else
            {
                cin >> V[lo];
                ++lo;
            }
        }
        cout << "SET " << c << endl;
        cout << V;
        ++c;
    }

    return 0;
}