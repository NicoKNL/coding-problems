#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<int> v;
    int n, tmp, q;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> tmp;
        vector<int>::iterator lower = lower_bound(v.begin(), v.end(), tmp);
        if (v[lower - v.begin()] == tmp) {
            cout << "Yes " << lower - v.begin() + 1 << endl;
        } else {
            cout << "No " << lower - v.begin() + 1 << endl;
        }
    }

    return 0;
}
