#include <bits/stdc++.h>

using namespace std;

int main() {
    int prices, max_price;
    cin >> prices >> max_price;

    vector<long long> items(prices);
    for (int i = 0; i < prices; i++) {
        cin >> items[i];
    }

    sort(items.begin(), items.end());

    if (items.size() == 1) {
        cout << 1 << endl;
    } else {
        int count = 1;
        for (int i = 1; i < items.size(); i++) {
            if (items[i] + items[i - 1] <= max_price) {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}