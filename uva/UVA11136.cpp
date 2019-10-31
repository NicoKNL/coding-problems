#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        multiset<int> bills;
        long cost = 0;
        int b, tmp;
        for (int i = 0; i < n; i++) {
            cin >> b;
            while (b--) {
                cin >> tmp;
                bills.insert(tmp);
            }
            cost += *bills.rbegin() - *bills.begin();
            bills.erase(bills.begin());
            bills.erase(prev(bills.end()));
        }
        cout << cost << endl;
    }

}