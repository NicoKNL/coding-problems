#include <bits/stdc++.h>
using namespace std;

int main()
{
    int check_range = 100;
    int nth_prime = 10001;
    vector<bool> not_prime(check_range);
    vector<long long> primes = {2};

    int current_prime = primes[primes.size() - 1];
    while (primes.size() < nth_prime) {
        for (long long i = 2 * current_prime; i < check_range; i += current_prime) {
            not_prime[i] = true;
        }

        if (current_prime >= check_range) {
            check_range *= 2;
            not_prime.resize(check_range, false);
            for (long long prime : primes) {
                for (long long i = 2 * prime; i < check_range; i += prime) {
                    not_prime[i] = true;
                }
            }
        }

        current_prime++;
        while (not_prime[current_prime] && current_prime < check_range) {
            current_prime++;
        }

        if (current_prime >= check_range) {
            current_prime = primes[primes.size() - 1];
            check_range = current_prime;
        } else {
            primes.push_back(current_prime);
        }
    }
    printf("%d", primes[primes.size() - 1]);
}
