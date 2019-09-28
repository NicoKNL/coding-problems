#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int degrees;
    while (n--) {
        cin >> degrees;
        degrees %= 360;
        if (degrees >= 180) {
            degrees -= 180;
        }
        degrees = (degrees + 5) / 10;
        if (degrees == 0) {
            cout << 18 << endl;
        }  else if (degrees < 10) {
            cout << 0 << degrees << endl;
        } else {
            cout << degrees << endl;
        }
    }
    return 0;
}