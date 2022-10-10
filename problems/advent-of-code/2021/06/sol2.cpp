#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long T;

ostream &operator<<(ostream &os, const map<int, T> &M)
{
    for (const auto &each : M)
    {
        os << each.first << ": " << each.second << endl;
    }
    return os;
}

int main()
{
    int n;
    map<int, T> M;

    while (cin >> n)
    {
        cout << n << endl;
        ++M[n];
    }
    cout << "initial state: " << endl;
    cout << M << endl;
    for (int day = 1; day <= 256; ++day)
    {
        map<int, T> next_M;

        for (const auto &each : M)
        {
            if (each.first == 0)
            {
                next_M[6] += each.second;
                next_M[8] += each.second;
            }
            else
            {
                next_M[each.first - 1] += each.second;
            }
        }

        M = next_M;
        cout << "After days #" << day << endl;
        cout << M << endl;
    }

    T total = 0;
    for (const auto &each : M)
    {
        total += each.second;
    }

    cout << total << endl;

    return 0;
}