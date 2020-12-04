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

int rotate(int n)
{
    string result = to_string(n);
    result = result[result.size() - 1] + result.substr(0, result.size() - 1);
    return stoi(result);
}

int main()
{
    int n = 1000000;
    vector<bool> prime = sieve(n);
    int result = 0;
    for (int base = 0; base < n; ++base) {
        if (!prime[base]) continue;
        int tmp = base;
        while (prime[tmp]) {
            tmp = rotate(tmp);
            if (tmp == base) {
                ++result;
                break;
            }
            if (!prime[tmp]) {
                break;
            }
        }
    }
    printf("%d\n", result);
}