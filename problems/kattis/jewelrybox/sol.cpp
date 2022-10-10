#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int X, Y;
        cin >> X >> Y;

        double a = 12.0;
        double b = -4.0 * (X + Y);
        double c = X * Y;

        double D = b * b - 4.0 * a * c;

        double root1 = (-b + sqrt(D)) / (2.0 * a);
        double root2 = (-b - sqrt(D)) / (2.0 * a);

        double volume1 = (X - 2.0 * root1) * (Y - 2.0 * root1) * root1;
        double volume2 = (X - 2.0 * root2) * (Y - 2.0 * root2) * root2;

        cout.precision(10);
        cout << max(volume1, volume2) << '\n';
    }
}