#include <bits/stdc++.h>

using namespace std;

int digitExpSum(int n, int exp)
{
    int result = 0;
    while (n > 0) {
        result += pow(n % 10, exp);
        n /= 10;
    }
    return result;
}

int main()
{
    int result = 0;
    int i = 2;
    while (i < 1000000) {
        if (i == digitExpSum(i, 5)) result += digitExpSum(i, 5);
        ++i;
    }
    printf("%d\n", result);
}