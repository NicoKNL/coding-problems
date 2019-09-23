#include <bits/stdc++.h>

using namespace std;

int main() {
    // Wrong bounds on the question... n >> 20.000
//    int n, m;
//    double f;
//    cin >> n >> m >> f;
//    double max_E = 0;
//    double E;
//    if (n == 1) {
//        cout << m << endl;
//        return 0;
//    }
//    for (int i = 1; i < n; i++) {
//        E = 1.0 / (n - i) * ((double) m - pow(i * f, 2));
//        if (E > max_E) max_E = E;
//    }
//    cout << setprecision(32) << max_E << endl;

    // Derivative style solution attempt
    int n, m;
    double f;
    cin >> n >> m >> f;
    if (n == 1) {
        cout << m << endl;
        return 0;
    }

    double f2 = pow(f, 2);
    cout << f2 << endl;
    double n2 = pow(n, 2);
    cout << n2 << endl;
    double x = f2 * n2 - m;
//    double x = sqrt(f2 * n2 - m) + f * n;
    // todo: finish this
    cout << x << endl;
    x /= f;
    cout << setprecision(32) << x << endl;
    return 0;
}