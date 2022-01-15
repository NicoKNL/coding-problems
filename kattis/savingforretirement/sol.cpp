#include <bits/stdc++.h>

using namespace std;

int main()
{
    int B, Br, Bs, A, As;
    cin >> B >> Br >> Bs >> A >> As;

    int target = 0;
    while (Br != B)
    {
        target += Bs;
        Br--;
    }

    int saved = 0;
    int years = 0;
    for (; saved <= target; ++years)
        saved += As;

    cout << A + years << endl;

    return 0;
}