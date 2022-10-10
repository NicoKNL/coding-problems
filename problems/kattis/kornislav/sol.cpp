#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> V(4, 0);
    cin >> V[0];
    cin >> V[1];
    cin >> V[2];
    cin >> V[3];

    sort(V.begin(), V.end());

    cout << V[0] * V[2] << endl;
    return 0;
}