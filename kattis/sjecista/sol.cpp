#include <bits/stdc++.h>

using namespace std;

unsigned long long choose(int n, int k)
{
    if (k == 0)
        return 1;

    return n * choose(n - 1, k - 1) / k;
}

int main()
{
    int n;
    cin >> n;

    cout << choose(n, 4) << endl;

    return 0;
}