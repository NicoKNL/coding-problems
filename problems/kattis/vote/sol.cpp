#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        vector<int> V(n + 1);

        int maxi = -1;
        int maxi_count = 0;
        int maxi_i = 0;
        int total = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> V[i];
            total += V[i];

            if (V[i] > maxi)
            {
                maxi = V[i];
                maxi_i = i;
                maxi_count = 0;
            }

            if (V[i] == maxi)
            {
                maxi_count += 1;
            }
        }

        if (maxi_count != 1)
        {
            cout << "no winner" << endl;
        }
        else
        {
            double factor = (double)V[maxi_i] / (double)total;

            if (factor > 0.5)
                cout << "majority winner " << maxi_i << endl;
            else
                cout << "minority winner " << maxi_i << endl;
        }
    }
    return 0;
}