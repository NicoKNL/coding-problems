#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<unsigned long long> V(n);

    for (int i = 0; i < n; ++i)
        cin >> V[i];

    int lo = -1;
    for (int i = 0; i < V.size(); ++i)
    {
        if (lo == -1)
            lo = i;
        else
        {
            if (V[i] % V[lo] == 0)
            {
                cout << V[i] << endl;
                lo = -1;
            }
        }
    }

    return 0;
}