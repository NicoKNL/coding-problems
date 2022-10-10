#include <bits/stdc++.h>

using namespace std;

int main()
{
    int E, F, C;
    cin >> E >> F >> C;

    E += F;
    int drinks = 0;
    while (E >= C)
    {
        int buy = E / C;
        drinks += buy;
        E -= buy * C;
        E += buy;
    }

    cout << drinks << endl;

    return 0;
}