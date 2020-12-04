#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int money, buy_count;
        cin >> money >> buy_count;

        vvi clothes;
        vector<vector<bool>> reachable(buy_count + 1, vector<bool>(money + 1, false));

        loop(i, buy_count) {
            int k;
            cin >> k;
            vi prices(k);
            loop(j, k) {
                cin >> prices[j];
            }
            clothes.push_back(prices);
        }

        // Initialize first row
        for (int p : clothes[0]) {
            if (money - p >= 0) reachable[0][money - p] = true;
        }

        // For all other rows
        for (int i = 1; i < buy_count; i++) {
            for (int m = 0; m < money; m++) {
                if (reachable[i-1][m]) {
                    for (int p : clothes[i]) {
                        if (m - p >= 0) {
                            reachable[i][m - p] = true;
                        }
                    }
                }
            }
        }

        int m = 0; // munnie
        for (m = 0; m <= money && !reachable[buy_count - 1][m]; m++){};

        if (m == money + 1) {
            printf("no solution\n");
        } else {
            printf("%d\n", money - m);
        }
    }
    return 0;
}