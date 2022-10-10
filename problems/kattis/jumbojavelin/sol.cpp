#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        int javelin;
        cin >> javelin;

        sum += javelin;
    }
    sum -= (n - 1);
    cout << sum << endl;

    return 0;
}