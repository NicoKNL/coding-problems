#include <bits/stdc++.h>

using namespace std;

double distance(pair<double, double> a, pair<double, double> b)
{
    auto [x1, y1] = a;
    auto [x2, y2] = b;

    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main()
{
    fixed(cout);
    cout.precision(9);

    vector<pair<double, double>> V(9);

    for (int r = 0; r < 3; ++r)
    {
        for (int c = 0; c < 3; ++c)
        {
            int i;
            cin >> i;

            V[i - 1] = {r, c};
        }
    }

    double dist = 0.0;
    for (int i = 0; i < 8; ++i)
        dist += distance(V[i], V[i + 1]);

    cout << dist << endl;

    return 0;
}