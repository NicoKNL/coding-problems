#include <bits/stdc++.h>

using namespace std;

bool isHarshad(int n)
{
    int tmp = n;
    int digitsum = 0;
    while (tmp)
    {
        digitsum += tmp % 10;
        tmp /= 10;
    }
    return n % digitsum == 0;
}

int main()
{
    int n;
    cin >> n;

    while (!isHarshad(n))
    {
        ++n;
    }

    cout << n << endl;
    return 0;
}