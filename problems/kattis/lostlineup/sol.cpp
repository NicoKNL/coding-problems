#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    set<pair<int, int>> lineup = {{-1, 1}};

    for (int i = 2; i <= n; ++i)
    {
        int dist;
        cin >> dist;
        lineup.insert({dist, i});
    }

    bool space = false;
    for (auto person : lineup)
    {
        if (space)
            cout << " ";

        cout << person.second;
        space = true;
    }
    cout << endl;

    return 0;
}