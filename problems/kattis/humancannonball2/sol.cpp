#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        double v, angle, x, h1, h2;
        cin >> v >> angle >> x >> h1 >> h2;

        h1 += 1.0;
        h2 -= 1.0;

        double angle_rad = angle * M_PI / 180.0;

        // get t
        double t = x / (v * cos(angle_rad));

        double y = v * t * sin(angle_rad) - 0.5 * 9.81 * t * t;

        if (h1 <= y && y <= h2)
        {
            cout << "Safe" << endl;
        }
        else
        {
            cout << "Not Safe" << endl;
        }
    }

    return 0;
}