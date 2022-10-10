#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) { return __gcd(a, b); }

long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

int main()
{
    int p, q, s;
    cin >> p >> q >> s;

    if (lcm(p, q) <= s)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}