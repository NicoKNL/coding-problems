#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    set<pair<int, int>> S;

    for (int i = 0; i < n; ++i)
    {
        pair<int, int> junk = {0, i};
        cin >> junk.first;
        S.insert(junk);
    }

    cout << (*S.begin()).second << endl;

    return 0;
}