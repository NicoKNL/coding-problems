#include <bits/stdc++.h>

using namespace std;

int right(int start, int end)
{
    int steps = 0;

    while (start != end)
    {
        start = (start + 1) % 360;
        ++steps;
    }

    return steps;
}

int left(int start, int end)
{
    int steps = 0;

    while (start != end)
    {
        start = (start - 1 + 360) % 360;
        --steps;
    }

    return steps;
}

int main()
{
    int a, b;
    cin >> a >> b;

    int L = left(a, b);
    int R = right(a, b);

    if (abs(L) == abs(R))
        cout << max(L, R) << endl;
    else if (abs(L) < abs(R))
        cout << L << endl;
    else
        cout << R << endl;

    return 0;
}