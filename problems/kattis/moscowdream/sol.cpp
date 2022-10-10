#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, n;
    cin >> a >> b >> c >> n;

    bool at_least_n = ((a + b + c) >= n);
    bool easy = (a >= 1);
    bool medium = (b >= 1);
    bool hard = (c >= 1);

    if (n >= 3 && at_least_n && easy && medium && hard)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}