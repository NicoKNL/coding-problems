#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    double n, init;
    cin >> n >> init >> k;

    vector<double> V = {0};
    for (int i = 1; i < n + 1; ++i)
    {
        V.push_back(V[i - 1] + (double)(i + 1) / 2.0);
        cout << V[i] << endl;
    }

    while (k--)
    {
        int i = floor(init);

        double expected_below = init * (double)(n - (double)i) / n;
        cout << ">>: " << V[n] << ", " << V[i] << endl;
        double expected_above = (n - i) / n * (V[n] + V[i]) / (n - i + 1);
        cout << expected_below << ", " << expected_above << endl;
        init = expected_below + expected_above;
        cout << init << endl;
    }

    cout << init << endl;
    // while (k--)
    // {
    //     vector<double> prob(n + 1, 0);
    //     for (int i = 1; i <= n; ++i)
    //     {
    //         if ((double)i < init)
    //         {
    //             prob[i] = (double)init;
    //         }
    //         else
    //         {
    //             prob[i] = (double)(i + 1) / 2.0;
    //         }
    //     }

    //     for (auto each : prob)
    //         cout << each << " ";
    //     cout << endl;

    //     init = accumulate(next(prob.begin()), prob.end(), 0.0) / (double)n;
    //     cout << init << endl;
    // }

    return 0;
}