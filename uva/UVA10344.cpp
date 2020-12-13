#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

bool recurse(vi & digits, int depth, long sum) {
    if (depth == 5) {
        return sum == 23;
    }

    long new_sum = 0;
    bool valid = false;
    if (depth == 0) {
        new_sum = digits[0];
        valid = recurse(digits, depth + 1, new_sum);
    } else {
        new_sum = sum + digits[depth];
        valid |= recurse(digits, depth + 1, new_sum);

        new_sum = sum - digits[depth];
        valid |= recurse(digits, depth + 1, new_sum);

        new_sum = sum * digits[depth];
        valid |= recurse(digits, depth + 1, new_sum);
    }
    return valid;
}

int main() {
    vi digits(5);
    while (cin >> digits[0] >> digits[1] >> digits[2] >> digits[3] >> digits[4]) {
        if (digits[0] == 0 && digits[1] == 0 && digits[2] == 0 && digits[3] == 0 && digits[4] == 0) break;

        bool possible = false;
        sort(digits.begin(), digits.end());
        do {
            possible = recurse(digits, 0, 0);
            if (possible) break;
        } while (next_permutation(digits.begin(), digits.end()));
        if (possible) printf("Possible\n");
        else printf("Impossible\n");
    }

    return 0;
}