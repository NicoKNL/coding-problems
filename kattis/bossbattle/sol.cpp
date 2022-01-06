#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n <= 3)
        cout << 1 << endl;
    else
        cout << n - 2 << endl;

    return 0;
}