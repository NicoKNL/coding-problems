#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    int n;
    while(cin >> n) {
        if (n == 0) break;

        vvi grid(n, vi(n, 0));
        loop(r, n) loop(c, n) cin >> grid[r][c];

        vi cols;
        vi rows;

        loop(r, n) {
            int sum = 0;
            loop(c, n) {
                sum += grid[r][c];
            }
            if (sum & 1) rows.push_back(r);
        }

        loop(c, n) {
            int sum = 0;
            loop(r, n) {
                sum += grid[r][c];
            }
            if (sum & 1) cols.push_back(c);
        }

        if (cols.size() == 0 && rows.size() == 0) {
            printf("OK\n");
        } else if (cols.size() == 1 && rows.size() == 1) {
            printf("Change bit (%d,%d)\n", rows[0] + 1, cols[0] + 1);
        } else {
            printf("Corrupt\n");
        }
    }
    return 0;
}