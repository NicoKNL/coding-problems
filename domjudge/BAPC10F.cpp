#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int days;
        cin >> days;
        int market;
        int profit = 0;
        int previous_best_profit = 0;
        int lower = 0;
        int upper = 0;
        int best_lower;
        int best_upper;
        for (int i = 0; i < days; i++) {
            cin >> market;
            if (profit + market < 0) { // reset potential lower
                lower = i + 1;
                profit = 0;
            } else if (profit + market > previous_best_profit) {
                previous_best_profit = profit + market;
                profit = previous_best_profit;
                best_lower = lower;
                best_upper = i;
            } else { //if (profit + market > 0) {
                profit = profit + market;
                upper = i;
            }
        }
        cout << best_lower + 1 << " " << best_upper + 1 << endl;
    }
    return 0;
}

/*
2
11
-3 1 -1 2 3 1 -1 2 -3 -5 7
9
1 -2 3 -1 -1 3 -2 2 -4

 // 2 8
 // 3 6

3
4
1 2 3 4
4
4 -1 -1 -1
4
-1 2 2 -1

 // 1 4
 // 1 1
 // 2 3
 */