#include <bits/stdc++.h>
using namespace std;

int main()
{
    long n = 2000000;
    vector<int> not_prime(n);
    vector<long> primes = {2};

    // Sieve
    while (primes[primes.size() - 1] < not_prime.size()) {
        for (long j = 2 * primes[primes.size() - 1]; j < not_prime.size(); j += primes[primes.size() - 1]) {
            not_prime[j] = 1;
        }

        // Find next prime
        int i = primes[primes.size() - 1] + 1;
        while (i < not_prime.size() && not_prime[i]) {
            i += 1;
        }
        primes.push_back(i);
    }
    long long sum = 0;
    for (int i = 0; i < primes.size() - 1; ++i) {
        sum += primes[i];
    }
    cout << sum;
}
