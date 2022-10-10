#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    vector<int> V;
    while (cin >> n)
    {
        V.push_back(n);
    }

    sort(V.begin(), V.end());
    int min = V[0];
    int max = V[V.size() - 1];

    vector<int> count(max + 1, 0);
    for (const auto &v : V)
        ++count[v];

    vector<int> prefix_sum(max + 1, 0);
    int active = 0;
    for (int i = 0; i < prefix_sum.size(); ++i)
    {
        if (i > 0)
            prefix_sum[i] += prefix_sum[i - 1];
        prefix_sum[i] += active;
        active += count[i];
    }

    vector<int> suffix_sum(max + 1, 0);
    active = 0;
    for (int i = suffix_sum.size() - 1; i >= 0; --i)
    {
        if (i < suffix_sum.size() - 1)
            suffix_sum[i] += suffix_sum[i + 1];
        suffix_sum[i] += active;
        active += count[i];
    }

    int optimal = INT32_MAX;
    int pos = -1;
    for (int i = min; i <= max; ++i)
    {
        int cost = prefix_sum[i] + suffix_sum[i];
        if (cost < optimal)
        {
            optimal = cost;
            pos = i;
        }
    }

    cout << optimal << endl;

    return 0;
}