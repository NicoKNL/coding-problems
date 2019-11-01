#include <bits/stdc++.h>

using namespace std;
vector<vector<long long>> sums;

void backtrack(int i, long long & s, long long & d, vector<long long> & sum) {
    if (i >= 5) {
        long long periodsum = 0;
        for (int j = i - 5; j < i; j++) {
            periodsum += sum[j];
        }
        if (periodsum >= 0) return;
    }
    if (i >= 12) {
        sums.push_back(sum);
        return;
    }
    sum[i] = s;
    backtrack(i+1, s, d, sum);
    sum[i] = -d;
    backtrack(i+1, s, d, sum);
}

int main() {
    long long s, d;
    while (cin >> s >> d) {
        vector<long long> sum(12);
        sums.clear();
        backtrack(0, s, d, sum);
        long long best = -1;
        long long current;
        for (auto vsum : sums) {
            current = accumulate(vsum.begin(), vsum.end(), 0);
            best = max(best, current);
        }
        if (best > 0) {
            cout << best << endl;
        } else {
            cout << "Deficit" << endl;
        }
    }
    return 0;
}