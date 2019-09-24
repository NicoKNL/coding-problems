#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    double f;
    cin >> n >> m >> f;
    double E;
    if (n == 1) {
        cout << m << endl;
        return 0;
    }

    int L, ML, MR, R;
    double EL, EML, EMR;
    L = 1;
    R = n;
    ML = n / 3;
    MR = 2*n / 3;

    while (R-L > 1000) {
        EL = 1.0 / (n - L) * ((double) m - pow(L * f, 2));
        EML = 1.0 / (n - ML) * ((double) m - pow(ML * f, 2));
        EMR = 1.0 / (n - MR) * ((double) m - pow(MR * f, 2));
        if (EL <= EML && EML >= EMR) { // left 2
            L = L;
            R = MR;
        } else {// right 2
            L = ML;
            R = R;
        }
        ML = L + (R - L) / 3;
        MR = L + 2 * (R - L) / 3;
    }
    double max_E = 0;
    for (int i = L; i <= R; i++) {
        E =  1.0 / (n - i) * ((double) m - pow(i * f, 2));
        if (E > max_E) max_E = E;
    }
    cout << setprecision(32) << max_E << endl;

    return 0;
}