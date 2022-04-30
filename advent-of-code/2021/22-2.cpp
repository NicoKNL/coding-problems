#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long result = 0;
    bool on;
    int x1, x2, y1, y2, z1, z2;
    while (cin >> on >> x1 >> x2 >> y1 >> y2 >> z1 >> z2)
    {
        unsigned long long volume = (unsigned long long)(abs(x2 - x1));
        volume *= (unsigned long long)(abs(y2 - y1));
        volume *= (unsigned long long)(abs(z2 - z1));

        if (on)
            result += volume;
        else
            result -= volume;
    }

    cout << result << endl;
}