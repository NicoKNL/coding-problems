#include <bits/stdc++.h>

using namespace std;

int main() {
    double p, q, r, s, t, u;
    while (cin >> p >> q >> r >> s >> t >> u) {
        double lo = 0, hi = 1;
        double x;
        bool found = false;
        double f;
        while (hi - lo > 0.000000001) {
            x = (lo + hi) / 2.0;
            f = p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x, 2) + u;
            if (abs(f) < 0.0000001) {
                found = true;
                break;
            }
            if (f > 0) lo = x;
            else hi = x;
        }
        if (!found) cout << "No solution" << endl;
        else cout << setprecision(4) << fixed << x << endl;
    }
    return 0;
}