#include <bits/stdc++.h>
using namespace std;

int main() {
    long n = 600851475143;
    vector<int> not_prime(floor(sqrt(n)) + 1);
    vector<long> primes = {1, 2};

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

    for (int i = primes.size() - 1; i >= 0; --i) {
        if (n % primes[i] == 0) {
            printf("%ld", primes[i]);
            return 0;
        }
    }
}
