#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vi> vvi;

#define loop(i, n) for (int i = 0; i < n; i++)

void build(vi & A, vvii & T, int width) {
    if (width == 1) return;
    map<int, int> M;
    int digit;
    int max_digit = -1;
    int max_count = -1;
    int prev_max_digit = -1;
    int prev_max_count = -1;
    for (int j = 0; j < width; j++) {
        digit = A[j];
        if (M.find(digit) != M.end()) {
            M[digit]++;
        } else {
            M[digit] = 1;
        }
        if (M[digit] > max_count) {
            prev_max_count = max_count;
            prev_max_digit = max_digit;
            max_digit = digit;
            max_count = M[digit];
        }
    }
    T[width].push_back({max_digit, max_count});
}

int main() {
    int n, queries;
    while (cin >> n) {
        if (n == 0) break;
        cin >> queries;
        vi vals(n);
        loop(i, n) cin >> vals[i];

        vvii T(n);
        build(vals, T, n + 1);

        int l, r;
        loop(i, queries) {
            cin >> l >> r;
            cout << tree.RMQ(l, r) << endl;
        }
    }

    return 0;
}