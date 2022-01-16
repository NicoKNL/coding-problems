#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    vector<int> in(3);
    vector<int> out(3);

    cin >> in[0] >> out[0];
    cin >> in[1] >> out[1];
    cin >> in[2] >> out[2];

    vector<int> V(101, 0);

    for (int i = 0; i < 3; ++i)
        for (int t = in[i]; t < out[i]; ++t)
            ++V[t];

    int cost = 0;
    for (int t = 1; t <= 100; ++t)
    {
        if (V[t] == 1)
            cost += A;
        if (V[t] == 2)
            cost += (2 * B);
        if (V[t] == 3)
            cost += (3 * C);
    }

    cout << cost << endl;

    return 0;
}