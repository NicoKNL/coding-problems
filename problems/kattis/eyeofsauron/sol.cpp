#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int len = s.length();
    if (len & 1)
    {
        cout << "fix" << endl;
        return 0;
    }

    if (s[len / 2 - 1] == '(' && s[len / 2] == ')')
        cout << "correct" << endl;
    else
        cout << "fix" << endl;

    return 0;
}