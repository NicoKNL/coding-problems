#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";

        int n;
        cin >> n;

        vector<long long> V1(n);
        vector<long long> V2(n);

        for (int ii = 0; ii < n; ++ii)
            cin >> V1[ii];

        for (int ii = 0; ii < n; ++ii)
            cin >> V2[ii];

        sort(V1.begin(), V1.end());
        sort(V2.begin(), V2.end());
        reverse(V2.begin(), V2.end());

        long long result = 0;

        for (int ii = 0; ii < n; ++ii)
            result += V1[ii] * V2[ii];

        cout << result << endl;
    }

    return 0;
}