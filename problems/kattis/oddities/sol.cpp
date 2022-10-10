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
        if (n & 1)
        {
            cout << n << " is odd" << endl;
        }
        else
        {
            cout << n << " is even" << endl;
        }
    }
    return 0;
}