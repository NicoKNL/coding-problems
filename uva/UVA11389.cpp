#include <bits/stdc++.h>

using namespace std;

int main() {
    int drivers, limit, rate;
    while (cin >> drivers >> limit >> rate) {
        if (drivers == 0 && limit == 0 && rate == 0) {
            break;
        }

        vector<int> morning(drivers);
        vector<int> evening(drivers);

        for (int i = 0; i < drivers; i++) {
            cin >> morning[i];
        }

        for (int i = 0; i < drivers; i++) {
            cin >> evening[i];
        }

        sort(morning.begin(), morning.end());
        sort(evening.begin(), evening.end());

        int overtime = 0;
        for (int i = 0; i < drivers; i++) {
            if (morning[i] + evening[evening.size() - 1 - i] > limit) {
                overtime += (morning[i] + evening[evening.size() - 1 - i]) - limit;
            }
        }
        printf("%d\n", overtime * rate);
    }
    return 0;
}