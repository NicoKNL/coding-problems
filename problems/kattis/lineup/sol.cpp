#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> V(n, "");

    for (int i = 0; i < n; ++i)
    {
        cin >> V[i];
    }

    vector<string> VINC = V;
    sort(VINC.begin(), VINC.end());

    vector<string> VDEC = VINC;
    reverse(VDEC.begin(), VDEC.end());

    if (V == VINC)
    {
        cout << "INCREASING" << endl;
    }
    else if (V == VDEC)
    {
        cout << "DECREASING" << endl;
    }
    else
    {
        cout << "NEITHER" << endl;
    }

    return 0;
}