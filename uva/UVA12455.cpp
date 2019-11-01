#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        int target, p;
        cin >> target >> p;
        vector<int> bars(p);
        for (int i = 0; i < p; i++) {
            cin >> bars[i];
        }

        int len;
        long long mask = 0;
        bool found = false;
        do {
            len = 0;
            for (int k = 0; k < p; k++) {
                if (mask & (1 << k)) {
                    len += bars[k];
                }
            }
            if (len == target) {
                found = true;
                break;
            }
            mask++;
        } while (mask < (1 << p));
        if (found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}