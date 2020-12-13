#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cases = 1;
    while (n--) {
        int k;
        cin >> k;
        vector<int> bricks(k);
        for (int i = 0; i < k; i++) {
            cin >> bricks[i];
        }

        printf("Case %d: %d\n", cases, bricks[k / 2]);
        cases++;
    }
    return 0;
}