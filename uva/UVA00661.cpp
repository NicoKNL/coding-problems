#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, c;
    int seq = 1;
    while (cin >> n >> m >> c) {
        if (n == 0 && m == 0 && c == 0) break;
        vector<int> device_on(n);
        vector<int> current(n);
        for (int i = 0; i < n; i++) {
            cin >> current[i];
        }

        int sum = 0;
        int max_sum = 0;
        int id;
        bool fuse = false;
        for (int i = 0; i < m; i++) {
            cin >> id;
            id--;
            if (device_on[id] == 1) {
                device_on[id] = 0;
                sum -= current[id];
            } else {
                device_on[id] = 1;
                sum += current[id];
                if (sum > c) fuse = true;
                max_sum = max(sum, max_sum);
            }
        }

        cout << "Sequence " << seq << endl;
        if (fuse) {
            cout << "Fuse was blown." << endl;
        } else {
            cout << "Fuse was not blown." << endl;
            cout << "Maximal power consumption was " << max_sum << " amperes." << endl;
        }
        cout << endl;
        seq++;
    }

    return 0;
}