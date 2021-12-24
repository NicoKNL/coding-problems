#include <bits/stdc++.h>

using namespace std;

int main()
{
    fixed(cout);
    cout.precision(10);

    double x1, y1, x2, y2, p;

    while (cin >> x1)
    {
        if (x1 == 0)
            break;

        cin >> y1 >> x2 >> y2 >> p;

        double result = pow(pow(abs(x1 - x2), p) + pow(abs(y1 - y2), p), 1.0 / p);
        cout << result << endl;
    }
    return 0;
}