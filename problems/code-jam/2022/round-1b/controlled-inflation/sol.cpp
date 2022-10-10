#include <bits/stdc++.h>

using namespace std;

unsigned long long solve()
{
    int n, p;
    cin >> n >> p;

    vector<pair<unsigned long long, unsigned long long>> ranges;

    for (int i = 0; i < n; ++i)
    {
        vector<unsigned long long> values;
        for (int ii = 0; ii < p; ++ii)
        {
            unsigned long long tmp;
            cin >> tmp;
            values.push_back(tmp);
        }

        sort(values.begin(), values.end());

        ranges.push_back({*values.begin(), *values.rbegin()});
    }

    priority_queue<pair<unsigned long long, int>> PQ;
    PQ.push({0, 0});
    unsigned long long best_cost = ULLONG_MAX;

    while (PQ.size())
    {
        auto current = PQ.top();
        PQ.pop();

        unsigned long long cost = current.first;
        int i = current.second;

        if (i == n)
        {
            best_cost = min(best_cost, cost);
            continue;
        }

        if (cost >= best_cost)
            continue;

        if (i == 0)
        {
            PQ.push({ranges[0].first, 1});
            PQ.push({ranges[0].second, 1});
        }
        else
        {
            unsigned long long prev_down_stop = ranges[i - 1].first;
            unsigned long long prev_up_stop = ranges[i - 1].second;

            unsigned long long current_range_cost = abs(ranges[i].first - ranges[i].second);
        }
    }
}

int main()
{
    int T;
    cin >> T;

    int c = 1;
    while (T--)
    {
        cout << "Case " << c << ": " << solve() << endl;
        ++c;
    }
}