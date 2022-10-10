#include <bits/stdc++.h>

using namespace std;

int main()
{
    fixed(cout);
    cout.precision(3);

    int n;
    cin >> n;

    while (n--)
    {
        int k;
        cin >> k;

        vector<double> V(k, 0.0);

        for (int i = 0; i < k; ++i)
            cin >> V[i];

        double avg = accumulate(V.begin(), V.end(), 0.0) / (double)k;

        sort(V.begin(), V.end());

        auto it = lower_bound(V.begin(), V.end(), avg);
        int count = 0;
        while (it != V.end())
        {
            if (*it > avg)
                ++count;
            ++it;
        }

        cout << (double)count / (double)k * 100.0 << "%" << endl;
    }

    return 0;
}