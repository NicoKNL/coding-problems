#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, tmp;
    while (cin >> n) {
        if (n == 0) break;
        long max_sum = 0;
        long sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            if (sum + tmp > 0) sum += tmp;
            else sum = 0;

            max_sum = sum > max_sum ? sum : max_sum;
        }
        if (max_sum > 0) {
            printf("The maximum winning streak is %d.\n", max_sum);
        } else {
            printf("Losing streak.\n");
        }
    }
    return 0;
}