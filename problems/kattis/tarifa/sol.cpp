#include <bits/stdc++.h>

using namespace std;

int main()
{
    int X, N;
    cin >> X >> N;

    int total = 0;

    for (int i = 0; i < N; ++i)
    {
        int tmp;
        cin >> tmp;

        total += X - tmp;
    }

    cout << total + X << endl;
    return 0;
}