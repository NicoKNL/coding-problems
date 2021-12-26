#include <bits/stdc++.h>

using namespace std;

int main()
{
    int X, Y;
    cin >> X >> Y;

    bool Y_is_odd = Y & 1;

    if (Y_is_odd)
        cout << "impossible" << endl;
    else
        cout << "possible" << endl;

    return 0;
}