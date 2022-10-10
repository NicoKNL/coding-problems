#include <bits/stdc++.h>

using namespace std;

int main() {
    int l, r;
    cin >> l >> r;
    if (l == r && l == 0) {
        printf("Not a moose\n");
    } else if (l == r) {
        printf("Even %d\n", l + r);
    } else {
        if (l > r) r = l;
        if (r > l) l = r;
        printf("Odd %d\n", l + r);
    }
    return 0;
}