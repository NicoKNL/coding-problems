#include <bits/stdc++.h>

using namespace std;

double regularCircleArea(double r)
{
    double pi = 3.14159265358979311599796346854419;
    return pi * r * r;
}

double hermanCircleArea(double r)
{
    double pi = 3.14159265358979311599796346854419;
    double factor = 2.0 / pi;
    return factor * regularCircleArea(r);
}

int main()
{
    fixed(cout);
    cout.precision(10);

    double r;
    cin >> r;

    cout << regularCircleArea(r) << endl;
    cout << hermanCircleArea(r) << endl;

    return 0;
}