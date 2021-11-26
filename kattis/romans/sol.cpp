#include <bits/stdc++.h>

using namespace std;

int main()
{
    fixed(cout);
    cout.precision(0);

    double x;
    cin >> x;

    double result = round(x * 1000.0 * 5280.0 / 4854.0);

    cout << result << endl;

    return 0;
}