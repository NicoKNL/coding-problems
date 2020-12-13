#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> sticks(n);
    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
    }
    sort(sticks.begin(), sticks.end());

    long long a, b, c;
    for (int i = 0; i < n - 2; i++) {
        a = sticks[i];
        b = sticks[i + 1];
        c = sticks[i + 2];
        if (a + b > c) {
            cout << "possible" << endl;
            return 0;
        }
    }
    cout << "impossible" << endl;
    return 0;
}