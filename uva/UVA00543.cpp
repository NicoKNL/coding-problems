#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vector<bool> Sieve(int n) {
    vector<bool> prime(n + 1, true);
    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * 2; i <= n; i+= p) {
                prime[i] = false;
            }
        }
    }
    return prime;
}

int main() {
    vector<bool> prime = Sieve(1000000);
    prime[1] = false;

    int n;
    while (cin >> n) {
        if (n == 0) break;
        for (int i = 2; i < n; i++) {
            if (prime[i] && prime[n-i]) {
                printf("%d = %d + %d\n", n, i, n-i);
                break;
            }
        }
    }
    return 0;
}