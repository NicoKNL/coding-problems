#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        double d, x, y;
        cin >> d >> x >> y;

        double dist = pow(pow(x, 2) + pow(y, 2), 1.0/2.0);
        double tmpdist = dist;
        double div = pow(d, 1.0 / 2.0);
        int jumps = 0;
        while (tmpdist > 0.000000001) {
            tmpdist -= div;
            jumps++;
        }
        if (jumps == 1 && div > dist) {
            jumps = 2;
        }
        cout << jumps << endl;
    }
    return 0;
}