#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, k;
    while (cin >> h >> k) {
        if (h == 0 && k == 0) break;
        vector<long long> heads(h);
        vector<long long> knights(k);
        for (int i = 0; i < h; i++) {
            cin >> heads[i];
        }
        for (int i = 0; i < k; i++) {
            cin >> knights[i];
        }

        sort(heads.begin(), heads.end());
        sort(knights.begin(), knights.end());

        int i = 0;
        int j = 0;
        long long gold = 0;
        while (i < heads.size() && j < knights.size()) {
            if (heads[i] <= knights[j]) {
                gold += knights[j];
                i++;
                j++;
            } else {
                j++;
            }
        }
        if (i == heads.size()) {
            printf("%d\n", gold);
        } else {
            printf("Loowater is doomed!\n");
        }
    }
    return 0;
}