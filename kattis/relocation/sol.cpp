#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;

    unordered_map<int, int> M;

    for (int i = 1; i <= N; ++i)
        cin >> M[i];

    while (Q--)
    {
        int OPT, A, B;
        cin >> OPT >> A >> B;

        if (OPT == 1)
            M[A] = B;

        if (OPT == 2)
        {
            int dist = abs(M[A] - M[B]);
            cout << dist << endl;
        }
    }

    return 0;
}