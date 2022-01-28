#include <bits/stdc++.h>

using namespace std;

double degreesToRadians(double degrees)
{
    return (degrees * M_PI) / 180.0;
}

int main()
{
    fixed(cout);
    cout.precision(10);

    int T;
    cin >> T;

    while (T--)
    {
        double n, l, d, g;
        cin >> n >> l >> d >> g;

        double perimeter = n * l;
        double apothem = l / (2.0 * tan(degreesToRadians(180.0 / n)));
        double initial_area = perimeter * apothem / 2.0;

        double growth_edges = g * d * l * n;
        double growth_corners = M_PI * pow(g * d, 2);

        cout << initial_area + growth_edges + growth_corners << endl;
    }

    return 0;
}