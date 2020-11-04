#include <bits/stdc++.h>

using namespace std;

vector<bool> sieve(int n)
{
    vector<bool> prime(n + 1, true);
    prime[0] = false; prime[1] = false;

    for (int p = 2; p * p <= n; ++p) {
        if (prime[p]) {
            for (int i = 2 * p; i <= n; i+= p) {
                prime[i] = false;
            }
        }
    }
    return prime;
}

long gcd(long a, long b)
{
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main()
{
    int n = 1000;
    vector<bool> prime = sieve(n);

    long d;
    for (int p = 1; p < n; ++p) {
        if (!prime[p]) continue;
        if (p == 1 || p == 2 || p == 5) continue;
        if (gcd(p, 10) != 1) continue;

        d = p;
    }
    printf("%d\n", d);
}