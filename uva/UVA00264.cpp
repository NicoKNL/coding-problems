#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

enum STATE {HORIZONTAL, DIAGDOWN, DIAGUP, VERTICAL};

int main() {
    int n;
    while (cin >> n) {
        int i = 1;
        ii pos = {1, 1};

        STATE state = HORIZONTAL;
        while (i < n) {
            if (state == HORIZONTAL) {
                pos.first += 1;
            } else if (state == DIAGDOWN) {
                pos.first -= 1;
                pos.second += 1;
            } else if (state == DIAGUP) {
                pos.first += 1;
                pos.second -= 1;
            } else { // state == VERTICAL
                pos.second += 1;
            }

            if (state == HORIZONTAL) {
                state = DIAGDOWN;
            } else if (state == VERTICAL) {
                state = DIAGUP;
            } else if (state == DIAGUP && pos.second == 1) {
                state = HORIZONTAL;
            } else if (state == DIAGDOWN && pos.first == 1) {
                state = VERTICAL;
            }
            i++;
        }

        printf("TERM %d IS %d/%d\n", n, pos.second, pos.first);
    }
    return 0;
}