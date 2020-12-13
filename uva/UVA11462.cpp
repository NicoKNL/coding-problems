#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, age;
    while (cin >> n) {
        if (n == 0) break;
        vector<int> ages(100);
        for (int i = 0; i < n; i++) {
            cin >> age;
            ages[age]++;
        }

        bool first = true;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < ages[i]; j++) {
                if (first) {
                    printf("%d", i);
                    first = false;
                } else {
                    printf(" %d", i);
                }
            }
        }
        printf("\n");
    }
}