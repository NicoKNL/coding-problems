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
        unsigned long long value = 0;

        while (n > 1)
        {
            if (value == 0)
                value = n;
            else
                value *= n;
            --n;
        }

        if (value == 0)
            cout << 1 << endl;
        else
            cout << value % 10 << endl;
    }
    return 0;
}