#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int N;
    cin >> N;

    vector<int> V(1001, 0);

    int A, MAX_A = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> A;
        ++V[A];
        MAX_A = max(MAX_A, V[A]);
    }

    cout << N - MAX_A << endl;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}