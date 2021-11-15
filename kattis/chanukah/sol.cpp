#include <bits/stdc++.h>

using namespace std;

int calculate(int n)
{
    int sum = (n * (n + 1) / 2) + n;
    return sum;
}

int main()
{
    int p;
    cin >> p;

    while (p--)
    {
        int k, n;
        cin >> k >> n;

        cout << k << " " << calculate(n) << endl;
    }

    return 0;
}