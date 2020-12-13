#include <bits/stdc++.h>
using namespace std;
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19};

vector<pair<int, int>> factorize(int n)
{
    vector<pair<int, int>> factors;
    for (int prime : primes) {
        int count = 0;
        while (n % prime == 0 && n > 0) {
            count++;
            n /= prime;
        }
        if (count > 0) {
            factors.push_back({prime, count});
        }
    }
    return factors;
}

int main()
{
    unordered_map<int, int> factors;
    for (int i = 2; i <= 20; ++i) {
        vector<pair<int, int>> f = factorize(i);
        for (pair<int, int> factor : f) {
            int base = factor.first;
            int exp = factor.second;

            if (factors.find(base) != factors.end()) {
                factors[base] = max(factors[base], exp);
            } else {
                factors[base] = exp;
            }
        }
    }

    long lcm = 1;
    for (pair<int, int> entry : factors) {
        int base = entry.first;
        int exp = entry.second;
        lcm *= pow(base, exp);
    }
    printf("%d", lcm);
}
