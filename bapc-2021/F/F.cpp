#include <bits/stdc++.h>

using namespace std;

struct Worker
{
    long b;
    long p;
};

vector<Worker>
parseInput()
{
    int n;
    cin >> n;
    vector<Worker> workers = {};

    while (n--)
    {
        long a, b;
        cin >> a >> b;
        workers.push_back({a, b});
    }

    return workers;
}

pair<long long, long long> sumSkills(const vector<Worker> &workers)
{
    long long sum_b = 0;
    long long sum_p = 0;

    for (const auto &w : workers)
    {
        sum_b += w.b;
        sum_p += w.p;
    }

    return {sum_b, sum_p};
}

bool cannotDivide(const vector<Worker> &workers)
{
    int n = workers.size();

    pair<long long, long long> sums = sumSkills(workers);
    long long sum_b = sums.first;
    long long sum_p = sums.second;

    return (sum_b % (n / 2)) || (sum_p % (n / 2));
}

bool canFormTeams(const vector<Worker> &workers)
{
    int n = workers.size();

    pair<long long, long long> sums = sumSkills(workers);
    long long sum_b = sums.first;
    long long sum_p = sums.second;

    long long target_b = sum_b / (n / 2);
    long long target_p = sum_p / (n / 2);

    map<pair<long long, long long>, int> M;

    for (const auto &w : workers)
    {
        ++M[{w.b, w.p}];
    }

    for (const auto &w : workers)
    {
        if (M[{w.b, w.p}] > 0)
        {
            if (M[{target_b - w.b, target_p - w.p}] > 0)
            {
                --M[{w.b, w.p}];
                --M[{target_b - w.b, target_p - w.p}];
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cout.precision(20);

    vector<Worker> workers = parseInput();

    if (workers.size() & 1 || cannotDivide(workers))
    {
        cout << "impossible" << endl;
        return 0;
    }

    if (canFormTeams(workers))
    {
        cout << "possible" << endl;
    }
    else
    {
        cout << "impossible" << endl;
    }

    return 0;
}
