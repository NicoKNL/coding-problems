#include <bits/stdc++.h>

using namespace std;

int main()
{
    fixed(cout);

    cout.precision(10);
    double n;
    cin >> n;

    n = pow(n, 1 / n);

    cout << n << endl;
    return 0;
}