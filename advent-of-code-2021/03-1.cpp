#include <bits/stdc++.h>

#define BITS 12
#define BITMASK 0b111111111111

using namespace std;

int main()
{
    string s;

    unsigned int gamma = 0;
    unsigned int epsilon = 0;

    vector<int> zero_count(BITS, 0);
    vector<int> one_count(BITS, 0);

    while (getline(cin, s))
    {
        stringstream ss;
        ss.str(s);

        string report;
        ss >> report;

        unsigned int r = stoi(report, nullptr, 2);
        bitset<BITS> rr(r);
        for (int i = 0; i < rr.size(); ++i)
        {
            if (rr[i])
                ++one_count[i];
            else
                ++zero_count[i];
        }
    }

    for (int i = 0; i < BITS; ++i)
    {
        if (one_count[i] > zero_count[i])
        {
            gamma += (1 << i);
        }
    }

    epsilon = gamma ^ BITMASK;

    bitset<BITS> g(gamma);
    bitset<BITS> e(epsilon);
    cout << g << endl;
    cout << e << endl;
    cout << gamma * epsilon << endl;

    return 0;
}