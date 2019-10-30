#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cout << "PERFECTION OUTPUT" << endl;
    while (cin >> n) {
        if (n == 0) break;
        int sum = 0;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) sum += i;
        }

        if (sum == n) {
            cout << setw(5) << n << "  PERFECT" << endl;
        } else if (sum < n) {
            cout << setw(5) << n << "  DEFICIENT" << endl;
        } else {
            cout << setw(5) << n << "  ABUNDANT" << endl;
        }
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}