#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, T;
    cin >> n >> T;

    for (int i = 1; i <= n; ++i)
    {
        int task;
        cin >> task;

        if (task <= T)
            T -= task;
        else
        {
            cout << i - 1 << endl;
            return 0;
        }
    }

    cout << n << endl;

    return 0;
}