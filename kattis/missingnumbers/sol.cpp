#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> V(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> V[i];

    int last = *V.rbegin();
    vector<int> V_all;
    for (int i = 1; i <= last; i++)
        V_all.push_back(i);

    vector<int> missed;
    set_symmetric_difference(V.begin(), V.end(), V_all.begin(), V_all.end(), back_inserter(missed));

    if (missed.size() > 0)
    {
        for (int each : missed)
        {
            cout << each << endl;
        }
    }
    else
    {
        cout << "good job" << endl;
    }

    return 0;
}