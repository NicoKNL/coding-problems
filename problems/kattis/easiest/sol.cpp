#include <bits/stdc++.h>

using namespace std;

int digitSum(int n)
{
    int sum = 0;

    while (n)
    {
        sum += (n % 10);
        n /= 10;
    }

    return sum;
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;

        int base_sum = digitSum(n);
        int alt_sum = -1;
        int i = 10;

        while (alt_sum != base_sum)
        {
            ++i;
            alt_sum = digitSum(n * i);
        }

        cout << i << endl;
    }

    return 0;
}