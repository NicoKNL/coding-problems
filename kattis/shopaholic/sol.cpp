#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> V(n);
    for (int i = 0; i < n; ++i)
        cin >> V[i];

    sort(V.begin(), V.end(), greater<long long>());

    long long discount = 0;
    for (int i = 0; i < n; ++i)
        if (i % 3 == 2)
            discount += V[i];

    cout << discount << endl;

    return 0;
}