#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> V(n, 0);

    for (int i = 0; i < n; ++i)
        cin >> V[i];

    sort(V.begin(), V.end(), [](int a, int b)
         { return a > b; });

    for (int i = 0; i < n; ++i)
        V[i] += (i + 1 + 1);

    int maxval = *max_element(V.begin(), V.end());
    cout << maxval << endl;

    return 0;
}