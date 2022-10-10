#include<bits/stdc++.h>
#define PI (2*std::acos(0.0))
// note: problem description is wrong. Order of variables in the input is denoted in the wrong order.
using namespace std;
int N = 100001;
int main() {
    double tape, radius;
    int ballsizes, balls;
    cin >> tape >> ballsizes;
    vector<double> BALLBIN;
    int j = 0;
    for (int i = 0; i < ballsizes; i++) {
        cin >> balls >> radius;
        while (balls--) {
            BALLBIN.push_back(radius);
            j++;
        }
    }

    sort(BALLBIN.begin(), BALLBIN.end());
    int counter = 0;
    int k = 0;
    while (tape >= 0 && k < BALLBIN.size()) {
        double length = 2.0 * BALLBIN[k] * PI; //pow((2.0 * BALLBIN[k]), 2) * PI;

        if (tape - length >= 0) {
            counter++;
            tape = tape - length;
        } else {
            break;
        }
        k++;

    }
    cout << counter << endl;

    return 0;
}