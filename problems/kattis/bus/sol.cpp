#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int k;
        cin >> k;

        double passengers = 0;
        while (k--)
        {
            passengers += 0.5;
            passengers *= 2.0;
        }

        cout << (unsigned long long)passengers << endl;
    }

    return 0;
}