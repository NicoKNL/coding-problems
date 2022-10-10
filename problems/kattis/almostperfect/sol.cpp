#include <bits/stdc++.h>

using namespace std;

set<long long> properDivisors(long long n)
{
    set<long long> factors = {1};

    for (long long i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            factors.insert(i);
            factors.insert(n / i);
        }
    }

    return factors;
}

int main()
{
    long long n;

    while (cin >> n)
    {
        long long sum = 0;

        for (long long f : properDivisors(n))
        {
            sum += f;
        }

        if (n == sum)
            cout << n << " perfect" << endl;
        else if (abs(n - sum) <= 2)
            cout << n << " almost perfect" << endl;
        else
            cout << n << " not perfect" << endl;
    }

    return 0;
}