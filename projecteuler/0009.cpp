#include <bits/stdc++.h>
using namespace std;

int main()
{
    for (int c = 997; c >= 3; c--) {
        for (int b = c - 1; b >= 2; b--) {
            for (int a = b - 1; a >= 1; a--) {
                if (a + b + c == 1000 && pow(a, 2) + pow(b, 2) == pow(c, 2)) {
                    printf("%d %d %d\n", a, b, c);
                    printf("%d", a * b * c);
                }
            }
        }
    }
}
