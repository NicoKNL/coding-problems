#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int statues = 1;
    int days = 1;
    while (statues < n)
    {
        statues *= 2;
        ++days;
    }

    cout << days << endl;

    return 0;
}