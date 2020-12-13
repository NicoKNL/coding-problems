#include <bits/stdc++.h>

using namespace std;

int next_comb(vector<int> & comb, int n) {
    int k = comb.size();
    int i = k - 1;
    ++comb[i];
    while ((i >= 0) && (comb[i] >= n - k + 1 + i)){
        --i; ++comb[i];
    }

    if (comb[0] > n - k) {
        // Combination (n-k, n-k+1, ..., n) reached
        return 0;
    }

    /* Comb now looks like (..., x, n, n, n, ..., n)
     * Turn it into (..., x, x + 1, x + 2, ...) */
    for (i = i + 1; i <= k; i++) {
        comb[i] = comb[i - 1] + 1;
    }
    return 1;
}

int main() {
    int n = 5; // Size of set: e.g. {1, 2, 3, 4} => 4
    int k = 3; // Size of subset: e.g. {1, 2}, {1, 3}, ... => 2
    vector<int> comb(k);
    for (int i = 0; i < k; i++) {
        comb[i] = i;
    }

    do {
        // Do something with the combination
        for (int i = 0; i < k; ++i) {
            cout << comb[i] << " ";
        }
        cout << endl;
    } while (next_comb(comb, n));
    return 0;
}