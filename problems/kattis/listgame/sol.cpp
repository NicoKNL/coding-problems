#include <bits/stdc++.h>

using namespace std;

vector<long long> primeFactors(long long n)
{
    vector<long long> factors;

    while (n % 2 == 0)
    {
        factors.push_back(2);
        n /= 2;
    }

    for (long long i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }

    if (n > 2)
        factors.push_back(n);

    return factors;
}

int main()
{
    long long X;
    cin >> X;

    vector<long long> factors = primeFactors(X);

    cout << factors.size() << endl;

    return 0;
}