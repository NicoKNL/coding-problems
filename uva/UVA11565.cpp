#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;


int main() {

    long limit = 10000;
    int n;
    cin >> n;
    while (n--) {
        long A, B, C;
        cin >> A >> B >> C;

        bool found = false;
        for (long x = -limit; x <= limit && !found; x++) {
            if (x == 0 || x * x > limit) continue;
            for (long y = -limit; y <= limit && !found; y++) {
                if (y == 0 || x * x + y * y > limit) continue;
                long z = A - x - y;
                if (x + y + z == A && x*y*z == B && x*x + y*y + z*z == C && x != y && y != z && x != z) {
                    printf("%d %d %d\n", x, y, z);
                    found = true;
                }

            }
        }
        if (!found) {
            printf("No solution.\n");
        }
    }
    return 0;
}