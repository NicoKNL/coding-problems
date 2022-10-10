#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> outcomes(N * M + 1, 0);
    int max_outcome = 0;

    for (int i = 1; i <= N; ++i)
    {
        for (int ii = 1; ii <= M; ++ii)
        {
            ++outcomes[i + ii];
            max_outcome = max(max_outcome, outcomes[i + ii]);
        }
    }

    for (int i = 1; i <= N * M + 1; ++i)
    {
        if (outcomes[i] == max_outcome)
            cout << i << endl;
    }

    return 0;
}