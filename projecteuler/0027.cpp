#include <bits/stdc++.h>

using namespace std;

bool isPrime(long long n)
{
    if (n < 2) return false;
    for (long long i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    int max_n = 0;
    int product = 0;
    for (long long a = -999; a < 1000; ++a) {
        for (long long b = -1000; b <= 1000; ++b) {
            int n = 0;
            while (isPrime(n * n + a * n + b)) {
                n++;
            }
            if (n > max_n) {
                max_n = n;
                product = a * b;
            }
        }
    }
    printf("%d\n", product);
}