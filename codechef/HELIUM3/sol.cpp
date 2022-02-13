#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        double A, B, X, Y;
        cin >> A >> B >> X >> Y;

        double total_power_required = A * B;
        double total_power_available = X * Y;

        if (total_power_available >= total_power_required)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}