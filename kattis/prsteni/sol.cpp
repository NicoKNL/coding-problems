#include <bits/stdc++.h>

using namespace std;

struct fraction
{
    long long num;
    long long denom;

    fraction(long long _num, long long _denom) : num(_num), denom(_denom)
    {
        long long gcd = __gcd(num, denom);

        if (gcd != 1)
        {
            num /= gcd;
            denom /= gcd;
        }
    }

    fraction operator*(fraction other)
    {
        return {num * other.num, denom * other.denom};
    }

    friend ostream &operator<<(ostream &os, fraction &f)
    {
        os << f.num << "/" << f.denom;
        return os;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> V(n);

    for (int i = 0; i < n; ++i)
        cin >> V[i];

    vector<fraction> fracs;

    for (int i = 0; i < n - 1; ++i)
        fracs.push_back(fraction(V[i], V[i + 1]));

    for (int i = 1; i < fracs.size(); ++i)
    {
        fraction prev = fracs[i - 1];
        fraction curr = fracs[i];

        fracs[i] = prev * curr;
    }

    for (auto f : fracs)
        cout << f << endl;

    return 0;
}