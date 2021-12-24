#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int len = s.length() / 3;
    unordered_set<string> S;

    for (int i = 0; i < 3; ++i)
    {
        string sub = s.substr(i * len, len);

        if (S.find(sub) != S.end())
        {
            cout << sub << endl;
            break;
        }

        S.insert(sub);
    }

    return 0;
}