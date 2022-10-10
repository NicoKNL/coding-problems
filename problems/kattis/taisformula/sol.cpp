#include <bits/stdc++.h>

using namespace std;

int main()
{
    fixed(cout);

    cout.precision(10);
    int n;
    cin >> n;

    double result = 0;
    double prev_value;
    double prev_t;

    for (int i = 0; i < n; ++i)
    {
        double value, t;
        cin >> t >> value;

        if (i > 0)
        {
            double tmp = (t - prev_t) * abs((value + prev_value) / 2.0);
            result += tmp;
        }

        prev_value = value;
        prev_t = t;
    }

    cout << result / 1000.0 << endl;

    return 0;
}