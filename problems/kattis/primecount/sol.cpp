#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

vector<unsigned int> primes; // will contain all primes up to sqrt(n)
unsigned long long PrimePi(unsigned long long n)
{
    if (!primes.empty() && primes.back() > n)
    {
        auto i = upper_bound(primes.begin(), primes.end(), n);
        return distance(primes.begin(), i);
    }

    auto v = (unsigned int)sqrt(n);

    vector<unsigned long long> higher(v + 2, 0);
    vector<unsigned int> lower(v + 2, 0);
    vector<bool> used(v + 2, false);

    unsigned long long result = n - 1;
    for (unsigned int p = 2; p <= v; p++)
    {
        lower[p] = p - 1;
        higher[p] = n / p - 1;
    }

    for (unsigned int p = 2; p <= v; p++)
    {
        if (lower[p] == lower[p - 1])
            continue;

        if (primes.empty() || p > primes.back())
            primes.push_back(p);

        auto temp = lower[p - 1];
        result -= higher[p] - temp;

        auto pSquare = (unsigned long long)p * p;
        auto end = min<unsigned long long>(v, n / pSquare);
        auto j = 1 + (p & 1);

        for (auto i = p + j; i <= end + 1; i += j)
        {
            if (used[i])
                continue;

            auto d = i * p;
            if (d <= v)
                higher[i] -= higher[d] - temp;
            else
                higher[i] -= lower[n / d] - temp;
        }

        for (auto i = v; i >= pSquare; i--)
            lower[i] -= lower[i / p] - temp;

        for (auto i = pSquare; i <= end; i += p * j)
            used[i] = true;
    }

    return result;
}

int main()
{
    long long n;
    cin >> n;
    cout << PrimePi(n) << endl;
}