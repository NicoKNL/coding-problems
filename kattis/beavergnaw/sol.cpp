#include <bits/stdc++.h>

using namespace std;

int main()
{
    fixed(cout);
    cout.precision(10);

    double D, V;

    while (true)
    {
        cin >> D >> V;
        if (D == 0 && V == 0)
            break;

        double v_total = M_PI * pow(D / 2.0, 2) * D;
        double result;
        double d = 0;
        double offset = D / 2.0;
        bool up = true;
        while (abs(result - V) > 0.0000001)
        {
            if (up)
                d += offset;
            else
                d -= offset;

            double v_center = M_PI * pow(d / 2.0, 2) * d;
            double v_cone_top = M_PI * pow(d / 2.0, 2) * ((d / 2.0) / 3.0);
            double v_cone_full = M_PI * pow(D / 2.0, 2) * ((D / 2.0) / 3.0);
            double v_cone = v_cone_full - v_cone_top;
            v_cone *= 2.0;

            result = v_total - v_center - v_cone;
            if (result < V)
            {
                if (up)
                    offset /= 10.0;

                up = false;
            }
            else
            {
                if (!up)
                    offset /= 10.0;

                up = true;
            }
        }

        cout << d << endl;
    }

    return 0;
}