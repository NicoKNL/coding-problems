#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cost_a, cap_a, cost_b, cap_b, n;
    cin >> cost_a >> cap_a >> cost_b >> cap_b >> n;

    int optimal_cost = INT_MAX;
    int drive_a = 0;
    int drive_b = 0;

    for (int a = 0; a < 101; ++a)
    {
        for (int b = 0; b < 101; ++b)
        {
            int cost = a * cost_a + b * cost_b;
            int shipped = a * cap_a + b * cap_b;
            if (cost < optimal_cost && shipped >= n)
            {
                drive_a = a;
                drive_b = b;
                optimal_cost = cost;
            }
        }
    }
    cout << drive_a << " " << drive_b << " " << optimal_cost << endl;
}