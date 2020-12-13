#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

/*
* calculates (a * b) % c taking into account that a * b might overflow
*/
long long int mulmod(long long int a, long long int b,
                     long long int mod) {
    long long int x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}
/*
* modular exponentiation
*/
long long int modulo(long long int base, long long int exponent,
                     long long int mod) {
    long long int x = 1;
    long long int y = base % mod;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            x = (x * y) % mod;
        }
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}

/*
* Miller-Rabin primality test, iteration signifies the accuracy
*/
bool Miller(long long int p,int iteration) {
    if (p < 2 || (p != 2 && p % 2==0)) {
        return false;
    }
    long long int s = p - 1;
    while (s % 2 == 0) {
        s /= 2;
    }
    for (int i = 0; i < iteration; i++) {
        long long int a = rand() % (p - 1) + 1;
        long long int temp = s;
        long long int mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1) {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int q;
    cin >> q;
    int k = 1;
    double root;
    double roundroot;
    do {
        root = pow(q, 1.0/ (double) k);

        roundroot = round(root);
        if (abs(roundroot - root) < EPS) { // if round digit
            if (Miller((long long) roundroot, 16)) {
                cout << "yes" << endl;
                return 0;
            }
        }
        k++;
    } while (root >= 2.0);
    cout << "no" << endl;
    return 0;
}