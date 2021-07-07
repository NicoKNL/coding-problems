#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define loop(i, n) for (int i = 0; i < n; i++)

vector<bool> Sieve(int n) {
    vector<bool> prime(n+1, true);
    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * 2; i <= n; i+= p) {
                prime[i] = false;
            }
        }
    }
    return prime;
}

void backtrack(int i, int n, vi & sol, vvi & solutions, vector<bool> & isPrime) {
    if (i == 0) {
        sol[0] = 1;
        backtrack(i+1, n, sol, solutions, isPrime);
    } else if (i == n) {
        if (isPrime[sol[n-1] + sol[0]]) solutions.push_back(sol);
    } else {
        for (int j = 2; j <= n; j++) {
            bool skip = false;
            for (int k = 0; k < i && !skip; k++) {
                if (sol[k] == j) skip = true;
            }
            sol[i] = j;
            if (!isPrime[sol[i] + sol[i-1]]) skip = true;
            if (!skip) {
                backtrack(i+1, n, sol, solutions, isPrime);
            }
        }
    }
}

int main() {
    vector<bool> primes = Sieve(50);
    int cases = 1;
    int n;
    while (cin >> n) {
        if (cases > 1) cout << endl;
        vi sol(n);
        vvi solutions;
        backtrack(0, n, sol, solutions, primes);

        printf("Case %d:\n", cases);
        loop(i, solutions.size()) {
            loop(j, solutions[i].size()) {
                if (j > 0) cout << " ";
                cout << solutions[i][j];
            }
            cout << endl;
        }
        cases++;
    }
    return 0;
}