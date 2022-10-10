#include <bits/stdc++.h>

using namespace std;

double brahmagupta(vector<double> v)
{
    double a = v[0];
    double b = v[1];
    double c = v[2];
    double d = v[3];

    double s = a + b + c + d;
    s /= 2.0;

    return sqrt((s - a) * (s - b) * (s - c) * (s - d));
}

int main()
{
    fixed(cout);
    cout.precision(20);

    double a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<double> sides = {a, b, c, d};
    sort(sides.begin(), sides.end());

    double best = 0;
    do
    {
        best = max(best, brahmagupta(sides));
    } while (next_permutation(sides.begin(), sides.end()));

    cout << best << endl;

    return 0;
}