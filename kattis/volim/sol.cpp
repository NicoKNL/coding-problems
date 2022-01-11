#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k, questions;
    cin >> k >> questions;

    int T = 210;

    while (questions--)
    {
        int t;
        char ans;
        cin >> t >> ans;

        T -= t;
        if (T <= 0)
            break;

        if (ans == 'T')
        {
            ++k;
            if (k == 9)
                k = 1;
        }
    }

    cout << k << endl;

    return 0;
}