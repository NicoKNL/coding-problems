#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    double f;
    cin >> n >> m >> f;
    double E1, E2;
    if (n == 1) {
        cout << m << endl;
        return 0;
    }

    int low = 1;
    int high = n;
    int stepsize = n / 3;

    E1 = 1.0 / (n - low) * ((double) m - pow(low * f, 2));
    while (stepsize > 0) {
        for (int i = low; i < high; i += stepsize) {
            E2 = 1.0 / (n - i) * ((double) m - pow(i * f, 2));
            if (E2 > E1) {
                E1 = E2;
                low = i - stepsize;
            }
        }
        stepsize /= 2;
    }

    cout << fixed << setprecision(9) << E1 << endl;

    return 0;
}
// todo: finish... TLE