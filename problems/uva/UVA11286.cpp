#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        map<vector<int>, int> m;
        for (int i = 0; i < n; i++) {
            int tmp;
            vector<int> values;
            for (int j = 0; j < 5; j++) {
                cin >> tmp;
                values.push_back(tmp);
            }
            sort(values.begin(), values.end());
            if (m.find(values) == m.end()) {
                m[values] = 1;
            } else {
                m[values] += 1;
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