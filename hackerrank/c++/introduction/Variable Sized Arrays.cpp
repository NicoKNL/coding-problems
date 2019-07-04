#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, q, k, tmp;
    vector<vector<int>> vec;
    vector<int> v;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> k;
        v = vector<int>();
        for (int j = 0; j < k; j++) {
            cin >> tmp;
            v.push_back(tmp);
        }
        vec.push_back(v);
    }

    int x, y;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        cout << vec.at(x).at(y) << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

