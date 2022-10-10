#include <bits/stdc++.h>

using namespace std;

int main()
{
    int lo = 1;
    int hi = 1000;

    string response;
    cout << (hi + lo) / 2 << endl;
    while (cin >> response)
    {
        if (response == "correct")
            break;

        if (response == "higher")
        {
            lo = (hi + lo) / 2 + 1;
        }

        if (response == "lower")
        {
            hi = (hi + lo) / 2 - 1;
        }

        cout << (hi + lo) / 2 << endl;
    }

    return 0;
}