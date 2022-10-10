#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int t0, d0;
    int t1, d1;
    int best_slope = 0;
    int slope;

    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            cin >> t0 >> d0;
        }
        else
        {
            cin >> t1 >> d1;
            slope = (d1 - d0) / (t1 - t0);
            best_slope = max(best_slope, slope);
            t0 = t1;
            d0 = d1;
        }
    }

    cout << best_slope << endl;

    return 0;
}