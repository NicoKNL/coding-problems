#include <bits/stdc++.h>

using namespace std;

int main()
{
    fixed(cout);
    cout.precision(10);

    int n;
    cin >> n;

    vector<double> V;
    for (int i = 0; i < n; ++i)
    {
        double minutes, seconds;
        cin >> minutes >> seconds;

        for (int ii = 0; ii < minutes; ++ii)
            V.push_back(seconds / (minutes * 60.0));
    }

    double avg = accumulate(V.begin(), V.end(), 0.0) / (double)V.size();

    if (avg > 1.0)
        cout << avg << endl;
    else
        cout << "measurement error" << endl;

    return 0;
}