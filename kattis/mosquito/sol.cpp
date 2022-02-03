#include <bits/stdc++.h>

using namespace std;

int main()
{
    int M, P, L, E, R, S, N;
    int M_, P_, L_, E_, R_, S_;

    while (cin >> M >> P >> L >> E >> R >> S >> N)
    {
        while (N--)
        {
            M_ = P / S;
            P_ = L / R;
            L_ = M * E;

            M = M_;
            P = P_;
            L = L_;
        }

        cout << M << endl;
    }

    return 0;
}