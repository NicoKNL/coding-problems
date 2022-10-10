#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 1;
    int b = 2;
    int sum = b;

    while (b < 4000000) {
        int tmp = a + b;
        a = b;
        b = tmp;
        if (b <= 4000000 & b % 2 == 0) {
            sum += b;
        }
    }
    printf("%d", sum);
}
