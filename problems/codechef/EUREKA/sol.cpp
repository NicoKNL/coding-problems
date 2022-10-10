#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        double n;
        cin >> n;

        double result = round(pow(0.143 * n, n));
        cout << (unsigned long long)result << endl;
    }

    return 0;
}