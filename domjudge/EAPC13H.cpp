#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, cost, parts, price;
    cin >> n;
    while (n--) {
        cin >> cost;
        cin >> m;
        while (m--) {
            cin >> parts >> price;
            cost += parts * price;
        }
        cout << cost << endl;
    }
    return 0;
}