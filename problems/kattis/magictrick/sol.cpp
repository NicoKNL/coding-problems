#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    set<char> S;

    for (const auto &c : s)
    {
        S.insert(c);
    }

    cout << (S.size() == s.length()) << endl;
    return 0;
}