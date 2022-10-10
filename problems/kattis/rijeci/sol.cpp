#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int A = 1;
    int B = 0;

    while (n--)
    {
        int _A = B;
        int _B = A + B;

        A = _A;
        B = _B;
    }

    cout << A << " " << B << endl;

    return 0;
}