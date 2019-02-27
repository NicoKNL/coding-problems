#include <iostream>
#include <map>

using namespace std;
// TODO: Test using uDebug
int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            int hash = 0;
            int tmp;
            for (int j = 0; j < 5; j++) {
                cin >> tmp;
                hash ^= tmp;
            }
            if (m.find(hash) == m.end()) {
                m[hash] = 1;
            } else {
                m[hash] += 1;
            }
        }

        int maxi = 0;
        int count = 0;
        for (auto it: m) {
            if (it.second > maxi) {
                maxi = it.second;
                count = 1;
            } else if (it.second == maxi) {
                count++;
            } else {
                continue;
            }
        }
        cout << maxi * count << endl;
    }
    return 0;
}