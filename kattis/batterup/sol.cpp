#include <bits/stdc++.h>

using namespace std;

int main()
{
    fixed(cout);
    cout.precision(20);

    int n;
    cin >> n;

    vector<double> V;

    for (int i = 0; i < n; ++i)
    {
        double tmp;
        cin >> tmp;

        if (tmp >= 0)
        {
            V.push_back(tmp);
        }
    }

    double sum = accumulate(V.begin(), V.end(), 0);
    sum /= V.size();

    cout << sum << endl;

    return 0;
}