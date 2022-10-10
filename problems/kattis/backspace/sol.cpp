#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    reverse(s.begin(), s.end());

    string result;

    int skip = 0;
    for (char c : s)
    {
        if (c == '<')
            ++skip;
        else if (skip)
            --skip;
        else
            result += c;
    }

    reverse(result.begin(), result.end());

    cout << result << endl;

    return 0;
}