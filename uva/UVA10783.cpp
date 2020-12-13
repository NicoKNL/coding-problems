#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int cases = 1;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        int sum = 0;
        for (int i = a; i <= b; i++) {
            if (i & 1) sum += i;
        }
        printf("Case %d: %d\n", cases, sum);
        cases++;
    }
    return 0;
}