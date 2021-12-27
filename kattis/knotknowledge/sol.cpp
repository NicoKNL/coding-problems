#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    set<int> S1;
    set<int> S2;

    for (int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;
        S1.insert(tmp);
    }

    for (int i = 0; i < n - 1; ++i)
    {
        int tmp;
        cin >> tmp;
        S2.insert(tmp);
    }

    vector<int> result;
    set_symmetric_difference(S1.begin(), S1.end(), S2.begin(), S2.end(), back_inserter(result));

    cout << result[0] << endl;

    return 0;
}