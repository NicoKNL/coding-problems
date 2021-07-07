#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        double warriors;
        cin >> warriors;
        double root = (-1 + sqrt(1 - 4 * -2 * warriors) ) / 2;
        cout << (long long) floor(root) << endl;
    }
    return 0;
}

