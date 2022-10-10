#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int attrs;
    string tmp, cat;
    while (n--) {
        map<string, int> m;
        cin >> attrs;
        while (attrs--) {
            cin >> tmp >> cat;
            if (m.find(cat) != m.end()) {
                m[cat]++;
            } else {
                m[cat] = 1;
            }
        }
        int total = 1;
        for (auto entry: m) {
            total *= (entry.second + 1);
        }
        cout << total - 1 << endl;
    }
    return 0;
}