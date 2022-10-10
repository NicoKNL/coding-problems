#include <bits/stdc++.h>

using namespace std;

int main()
{
    fixed(cout);
    cout.precision(10);

    double r, m, c;
    while (true)
    {
        cin >> r >> m >> c;
        if (r == 0 && m == 0 && c == 0)
            break;

        double area = M_PI * r * r;
        double area_approx = c / m * (2 * r) * (2 * r);
        cout << area << " " << area_approx << endl;
    }

    return 0;
}