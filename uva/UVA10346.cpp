#include <bits/stdc++.h>

using namespace std;

int main() {
    int cigs, k;
    while (cin >> cigs >> k) {
        int sum = 0;
        int butts = cigs;
        while (butts >= k) {
            sum += cigs;
            cigs = butts / k;
            butts -= (butts / k) * k;
            butts += cigs;
        }
        sum += cigs;
        cout << sum << endl;
    }

    return 0;
}