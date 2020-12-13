#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<bool> Sieve(long n) {
    vector<bool> prime(n, true);
    prime[0] = false; // 0 = 1
    for (long p = 1; p * p <= n; p++) {
        if (prime[p]) {
            for (long i = p * 2; i <= n; i+= p) {
                prime[i] = false;
            }
        }
    }
    return prime;
}

// TODO: finish, sieve needs to go up to INT_MAX + 1, or offset all by 1, or use bitset
int main() {
    vector<bool> prime = Sieve(INT_MAX);
    long L, U;
    while (cin >> L >> U) {
        vector<long> primes;
        for (long i = L - 1; i < U; i++) {
            if (prime[i]) primes.push_back(i + 1);
        }

        if (primes.size() < 2) {
            printf("There are no adjacent primes.\n");
        } else {
            vector<pair<int, pair<int, int>>> dist;
            loop(i, primes.size() - 1) {
                dist.push_back({primes[i + 1] - primes[i], {primes[i], primes[i+1]}});
            }
            sort(dist.begin(), dist.end());
            printf("%d,%d are closest, %d,%d are most distant.\n", dist[0].second.first, dist[0].second.second, dist[dist.size() - 1].second.first, dist[dist.size() - 1].second.second);
        }
    }
    return 0;
}