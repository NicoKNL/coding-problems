#include <bits/stdc++.h>

#define BITS 12
using namespace std;
typedef vector<bitset<BITS>> T;

pair<T, T> groupZeroOne(const T &reports, int i)
{
    T zero;
    T one;
    for (const auto &r : reports)
    {
        if (r[i] == 1)
        {
            one.push_back(r);
        }
        else
        {
            zero.push_back(r);
        }
    }

    return {zero, one};
}

void filterOxy(T &reports, int i)
{
    T zero, one;
    tie(zero, one) = groupZeroOne(reports, i);

    if (one.size() >= zero.size())
    {
        reports = one;
    }
    else
    {
        reports = zero;
    }
}

void filterCo2(vector<bitset<BITS>> &reports, int i)
{
    T zero, one;
    tie(zero, one) = groupZeroOne(reports, i);

    if (one.size() < zero.size())
    {
        reports = one;
    }
    else
    {
        reports = zero;
    }
}

int main()
{
    string s;

    unsigned int gamma = 0;
    unsigned int epsilon = 0;

    vector<bitset<BITS>> reports;
    while (getline(cin, s))
    {
        stringstream ss;
        ss.str(s);

        string report;
        ss >> report;

        unsigned int r = stoi(report, nullptr, 2);
        bitset<BITS> rr(r);

        reports.push_back(rr);
    }

    vector<bitset<BITS>> oxy(reports);
    vector<bitset<BITS>> co2(reports);
    for (int i = BITS - 1; i >= 0; --i)
    {
        if (oxy.size() > 1)
            filterOxy(oxy, i);
        if (co2.size() > 1)
            filterCo2(co2, i);
    }

    cout << oxy.size() << endl;
    cout << co2.size() << endl;

    unsigned int oxyval = oxy[0].to_ulong();
    unsigned int co2val = co2[0].to_ulong();
    cout << oxyval * co2val << endl;
    return 0;
}