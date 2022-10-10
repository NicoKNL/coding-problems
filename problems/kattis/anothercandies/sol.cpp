#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        unsigned long long n;
        cin >> n;

        unsigned long long candies = 0;
        for (int i = 0; i < n; ++i)
        {
            unsigned long long candy;
            cin >> candy;

            candies += candy;
            candies %= n;
        }

        if (candies == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}