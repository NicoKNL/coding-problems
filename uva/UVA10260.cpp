#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    string s;
    vector<int> charval = {
            // A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z
               0, 1, 2, 3, 0, 1, 2, 0, 0, 2, 2, 4, 5, 5, 0, 1, 2, 6, 2, 3, 0, 1, 0, 2, 0, 2
    };
    while (getline(cin, s)) {
        string score;
        int prev = -1;
        for (char c : s) {
            int c_digit = charval[c-'A'];
            if (c_digit != prev && c_digit != 0) {
                score += to_string(charval[c - 'A']);
            }
            prev = c_digit;
        }
        cout << score << endl;
    }
    return 0;
}