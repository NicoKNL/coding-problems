#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> V(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> V[i];
    }

    int sum = accumulate(V.begin(), V.end(), 0);
    cout << sum << endl;
    return 0;
}