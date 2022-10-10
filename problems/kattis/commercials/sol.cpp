#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, P;
    cin >> N >> P;

    vector<int> V(N, 0);
    int sum = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> V[i];
        V[i] -= P;
    }

    int optimal_profit = INT32_MIN;
    int profit = 0;
    for (int i = 0; i < N; ++i)
    {
        profit += V[i];

        profit = max(profit, 0);

        optimal_profit = max(profit, optimal_profit);
    }

    cout << optimal_profit << endl;

    return 0;
}