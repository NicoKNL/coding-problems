#include <bits/stdc++.h>

using namespace std;

int main()
{
    fixed(cout);
    cout.precision(0);

    double h, v;
    cin >> h >> v;

    double rad = v * M_PI / 180.0;
    double r = ceil(h / sin(rad));

    cout << r << endl;

    return 0;
}