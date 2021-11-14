#include <bits/stdc++.h>

using namespace std;

int main()
{
    fixed(cout);
    cout.precision(20);

    double C_cost;
    int L_lawns;

    cin >> C_cost >> L_lawns;

    double total_cost = 0.0;

    for (int i = 0; i < L_lawns; ++i)
    {
        double w, l;

        cin >> w >> l;
        total_cost += w * l * C_cost;
    }

    cout << total_cost << endl;

    return 0;
}