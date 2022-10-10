#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int N, X;
    cin >> N >> X;

    vector<int> V(N, 0);

    for (int i = 0; i < N; ++i)
        cin >> V[i];

    set<int> S;

    bool possible = true;
    for (int i = N - 1; i >= 0 && possible; --i)
    {
        if (i == N - 1)
            S.insert(V[i]);
        else
        {
            auto max_below_on_right_it = S.lower_bound(V[i]);
            if (max_below_on_right_it != S.begin())
            {
                --max_below_on_right_it;
                int max_below_on_right = *max_below_on_right_it;

                if (V[i] + max_below_on_right > X)
                    possible = false;
            }

            S.insert(V[i]);
        }
    }

    if (possible)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}