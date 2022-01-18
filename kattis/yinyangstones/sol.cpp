#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int black = 0;
    int white = 0;

    for (char c : s)
        if (c == 'W')
            ++white;
        else
            ++black;

    cout << (white == black) << endl;

    return 0;
}