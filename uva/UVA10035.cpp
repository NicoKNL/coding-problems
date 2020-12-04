#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) {
        if (a == 0 && b == 0) break;

        int i = 1;
        int carries = 0;
        int carry = 0;
        while(true) {
            int x = (a / i) % 10;
            int y = (b / i) % 10;
            if (x > 0 || y > 0 || carry > 0 || i < a || i < b) {
                x += y;
                x += carry;
                carry = 0;
                if (x >= 10) {
                    carry = x / 10;
                    carries++;
                }
            } else {
                break;
            }
            i *= 10;
        }
        if (carries == 0) {
            printf("No carry operation.\n");
        } else if (carries == 1) {
            printf("1 carry operation.\n");
        } else {
            printf("%d carry operations.\n", carries);
        }
    }
    return 0;
}