#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<long long, int> triangular_divs = {{0, 0}};

    // TODO: Improve using formula for total number of divisors of any given n, and the fact that n and n+1 are coprime. (gcd(n, n+1) = 1)

    int i = 12000;
    bool found = false;
    while (!found) {
        long long x = (i * (i + 1)) / 2;
        printf("%d : %lld : ", i, x);
        int divisors = 1;
        for (long long j = x / 2; j > 0; --j) {
            if (x % j == 0) {
                if (triangular_divs.find(j) != triangular_divs.end()) {
//                    printf("hit on %lld\n", j);
                    divisors += triangular_divs[j];
                    break;
                } else {
                    ++divisors;
                }
            }
        }
        int tmp = divisors / 10;
        while (tmp > 0) {
            printf(" ");
            --tmp;
        }
        printf("%d\n", divisors);
        triangular_divs[x] = divisors;
        if (divisors > 500) {
            found = true;
            printf("%lld", x);
        }
        ++i;
    }
}
