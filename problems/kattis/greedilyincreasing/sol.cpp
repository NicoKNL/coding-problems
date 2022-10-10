#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> V(n);
    for (int i = 0; i < n; ++i)
        cin >> V[i];

    vector<int> GIS = {V[0]};
    int g_i = 0;
    for (int i = 1; i < n; ++i)
        if (V[i] > GIS[g_i])
        {
            GIS.push_back(V[i]);
            ++g_i;
        }

    cout << GIS.size() << endl;

    for (int i = 0; i < GIS.size(); ++i)
    {
        if (i > 0)
            cout << " ";
        cout << GIS[i];
    }

    cout << endl;

    return 0;
}