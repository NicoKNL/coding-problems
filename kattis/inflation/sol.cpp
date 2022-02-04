#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin >> n;

    vector<int> gas;
    vector<int> balloons;

    for (int i = 0; i < n; ++i)
    {
        balloons.push_back(i + 1);

        int g;
        cin >> g;
        gas.push_back(g);
    }

    sort(gas.begin(), gas.end());

    double ratio = 1.0;

    bool possible = true;
    for (int i = 0; i < n; ++i)
    {
        if (gas[i] > balloons[i])
            possible = false;

        ratio = min(ratio, (double)gas[i] / (double)balloons[i]);
    }

    if (possible)
        cout << ratio << endl;
    else
        cout << "impossible" << endl;

    return 0;
}