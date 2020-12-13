#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int mics;
        double xp, yp, xi, yi, si;
        double noise;
        double noise_sum = 0;
        double ri;
        cin >> mics >> noise >> xp >> yp;
        vector<double> ris(mics);

        for (int i = 0; i < mics; i++) {
            cin >> xi >> yi >> si;
            ri = pow(xp - xi, 2.0) + pow(yp - yi, 2.0);
            ri = si / ri;
            ris[i] = ri;
            noise_sum += ri;
        }

        bool found = false;
        for (int i = 0; i < mics; i++) {
            if (ris[i] / 6.0 > noise + noise_sum - ris[i]) {
                found = true;
                cout << i + 1 << endl;
                break;
            }
        }

        if (!found) {
            cout << "NOISE" << endl;
        }
    }
    return 0;
}
/*
3
4
10
100 100
90 90 20000
110 90 50
90 110 1000
110 110 50
4
100
100 100
90 90 20000
110 90 50
90 110 1000
110 110 50
2
0
0 10
0 0 1000
0 8 1
*/