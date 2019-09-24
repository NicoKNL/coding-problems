#include<bits/stdc++.h>
//todo: finish
using namespace std;

int main() {
    int n;
    cin >> n;
    int a, b, c, d;
    while (n--) {
        cin >> a >> b >> c;
        d = c % 100;
        c = c / 100;
        vector<int> digits(10); // 0 - 9
        digits[a/10]++;
        digits[a%10]++;
        digits[b/10]++;
        digits[b%10]++;
        digits[c/10]++;
        digits[c%10]++;
        digits[d/10]++;
        digits[d%10]++;
        bool split = false;
        if ((a + b == c + d) || (a + c == b + d) || (a + d == b + c) ||
        (a + b + c == d) || (a + b + d == c) || (a + c + d == b) || (b + c + d == a)) {
            split = true;
        }

        bool even = true;
        int base = -1;
        for (int i = 0; i < 10; i++) {
            if (digits[i] == 0) continue;
            if (base == -1) base = digits[i];
            if (digits[i] != base) even = false;
        }

        if (!even || !split) {
            printf("no\n");
        } else {
            printf("yes\n");
        }
    }
    return 0;
}