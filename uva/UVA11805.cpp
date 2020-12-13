#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    int cases = 1;
    while (t--) {
        int n, k, p;
        cin >> n >> k >> p;

        printf("Case %d: %d\n", cases, (p % n + k - 1) % n + 1);
        cases++;
    }
    return 0;
}