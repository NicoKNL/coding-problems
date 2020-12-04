#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

bool check(int top, int bot) {
    vi counter(10, 0);
    if (top < 9999 || bot < 9999) {
        counter[0] = 1;
    }

    while (top) {
        counter[top % 10]++;
        top /= 10;
    }

    while (bot) {
        counter[bot % 10]++;
        bot /= 10;
    }

    loop(i, 10) {
        if (counter[i] != 1) return false;
    }
    return true;
}

int main() {
    int N;
    int cases = 1;
    while (cin >> N) {
        int top;
        bool found = false;
        if (N == 0) break;
        if (cases > 1) cout << endl;
        for (int bot = 1234; bot < 98765; bot++) {
            top = N * bot;
            if (check(top, bot)) {
                found = true;
                printf("%05d / %05d = %d\n", top, bot, N);
            }
        }
        if (!found) {
            printf("There are no solutions for %d.\n", N);
        }

        cases++;
    }

    return 0;
}