#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, pirates, itemcount;
    cin >> n;
    while (n--) {
        cin >> pirates >> itemcount;
        vector<int> items(itemcount);
        for (int i = 0; i < itemcount; i++) {
            cin >> items[i];
        }
        sort(items.begin(), items.end());
        int take = itemcount / (pirates + 1);
        int sum = 0;
        for (int i = 0; i < take; i++) {
            sum += items[items.size() - i - 1];
        }
        cout << sum << endl;
    }
    return 0;
}