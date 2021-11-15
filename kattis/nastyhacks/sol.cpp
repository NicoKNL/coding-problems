#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int r, e, c;
        cin >> r >> e >> c;

        int diff = e - c - r;

        if (diff == 0)
        {
            cout << "does not matter" << endl;
        }
        else if (diff > 0)
        {
            cout << "advertise" << endl;
        }
        else
        {
            cout << "do not advertise" << endl;
        }
    }

    return 0;
}