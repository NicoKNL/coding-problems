#include <bits/stdc++.h>

using namespace std;

unsigned long long solve(int n, int b)
{
    unsigned long long result = 0;
    while (n)
    {
        int digit = n % b;
        result += pow(digit, 2);
        n /= b;
    }

    return result;
}

int main()
{
    int P;
    cin >> P;

    while (P--)
    {
        int K, b;
        int n;
        cin >> K >> b >> n;
        cout << K << " " << solve(n, b) << endl;
    }

    return 0;
}