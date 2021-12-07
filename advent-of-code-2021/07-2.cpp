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
    int active;

    for (int i = 0; i < prefix_sum.size(); ++i)
    {
        active = 0;
        for (int ii = i; ii < prefix_sum.size(); ++ii)
        {
            active += (ii - i) * count[i];
            prefix_sum[ii] += active;
        }
    }

    vector<int> suffix_sum(max + 1, 0);
    active = 0;
    for (int i = suffix_sum.size() - 1; i >= 0; --i)
    {
        active = 0;
        for (int ii = i; ii >= 0; --ii)
        {
            active += (i - ii) * count[i];
            suffix_sum[ii] += active;
        }
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