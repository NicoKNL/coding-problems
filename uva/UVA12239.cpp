#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, B;
    while (cin >> N >> B) {
        if (N == 0 && B == 0) break;
        vector<int> balls(B);
        vector<int> numbers(N + 1);
        for (int i = 0; i < B; i++) {
            cin >> balls[i];
        }

        for (int ba : balls) {
            for (int bb : balls) {
                numbers[abs(ba - bb)] = 1;
            }
        }

        bool possible = true;
        for (int i = 0; i < N + 1; i++) {
            if (numbers[i] == 0) possible = false;
        }

        if (possible) {
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
    }

    return 0;
}