#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int cost = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (i % 3 == 0 && s[i] != 'P')
            ++cost;
        if (i % 3 == 1 && s[i] != 'E')
            ++cost;
        if (i % 3 == 2 && s[i] != 'R')
            ++cost;
    }
    cout << cost << endl;
    return 0;
}