#include<bits/stdc++.h>
//todo: finish
using namespace std;

bool evenDigits(int a, int b, int c, int d) {
    vector<int> digits(10); // 0 - 9
    // Single digits
    digits[a%10]++;
    digits[b%10]++;
    digits[c%10]++;
    digits[d%10]++;

    // If double digits
    if (a > 9) {
        digits[a/10]++;
    }
    if (b > 9) {
        digits[b/10]++;
    }
    digits[c/10]++;
    digits[d/10]++;

//    for (int i = 0; i < 10; i++) {
//        cout << digits[i] << endl;
//    }
    bool even = true;
    int base = -1;
    for (int i = 0; i < 10; i++) {
        if (digits[i] == 0) continue;
        if (base == -1) base = digits[i];
        if (digits[i] != base) even = false;
    }
    return even;
}

bool canSplit(int a, int b, int c, int d) {
    int tmpA, tmpB;
    for (int i = 1; i < 15; i++) {
        tmpA = 0;
        tmpB = 0;
        if ((1 & i) > 0) {
            tmpA += a;
        } else {
            tmpB += a;
        }

        if ((2 & i) > 0) {
            tmpA += b;
        } else {
            tmpB += b;
        }

        if ((4 & i) > 0) {
            tmpA += c;
        } else {
            tmpB += c;
        }

        if ((8 & i) > 0) {
            tmpA += d;
        } else {
            tmpB += d;
        }

        if (tmpA == tmpB) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int a, b, c, d;
    while (n--) {
        cin >> a >> b >> c;
        d = c % 100;
        c = c / 100;

        bool even = evenDigits(a, b, c, d);
        bool split = canSplit(a, b, c, d);
        if (even && split) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}