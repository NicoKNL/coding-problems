#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    if (s[0] == '5' && s[0] == s[1] && s[1] == s[2])
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}