#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int d;
        cin >> d;

        vector<int> count (10, 0);
        for (int i = 1; i <= d; i++) {
            int tmp = i;
            while (tmp) {
                count[tmp % 10]++;
                tmp /= 10;
            }
        }
        for (int i = 0; i < 10; i++) {
            if (i > 0) cout << " ";
            cout << count[i];
        }
        cout << endl;
    }

    return 0;
}