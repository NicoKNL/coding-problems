#include <bits/stdc++.h>

using namespace std;

ostream &operator<<(ostream &os, vector<string> &V)
{
    for (string s : V)
        os << s << endl;
    return os;
}

int main()
{
    int n;
    bool first = true;
    while (cin >> n)
    {
        if (n == 0)
            break;

        if (!first)
            cout << endl;

        first = false;

        vector<string> V(n, "");

        for (int i = 0; i < n; ++i)
            cin >> V[i];

        stable_sort(V.begin(), V.end(), [](const string &a, const string &b)
                    {
                        if (a[0] < b[0])
                            return true;
                        else if (a[0] == b[0] && a[1] < b[1])
                            return true;
                        return false;
                    });

        cout << V;
    }

    return 0;
}