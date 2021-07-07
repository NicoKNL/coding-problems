#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, digit, k;
    while (cin >> n >> m) {
        vector<int> *map = new vector<int>[1000001];
        for (int i = 1; i <= n; i++) {
            cin >> digit;
            map[digit].push_back(i);
        }

        while (m--) {
            cin >> k >> digit;

            if (map[digit].size() < k) {
                cout << 0 << endl;
            } else {
                cout << map[digit][k - 1] << endl;
            }
        }

        delete[] map;
    }
    return 0;
}