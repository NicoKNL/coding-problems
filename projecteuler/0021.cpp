#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> divsums = {0};

    for (int i = 1; i < 10000; ++i) {
        int sum = 0;
        for (int j = 1; j < i; ++j) {
            if (i % j == 0) {
                sum += j;
            }
        }

        divsums.push_back(sum);
    }

    int result = 0;
    for (int a = 1; a < 10000; ++a) {
        int b = divsums[a];
        if (b >= 10000 || a == b) continue;
        if (divsums[a] == b && divsums[b] == a) {
            result += a;
        }
    }
    printf("result: %d\n", result);
}
