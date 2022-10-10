#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    string s_out;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] != s_out.back())
        {
            s_out += s[i];
        }
    }

    cout << s_out << endl;

    return 0;
}