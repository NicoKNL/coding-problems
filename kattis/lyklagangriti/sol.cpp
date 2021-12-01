#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, result;
    cin >> s;

    list<char> L;

    auto it = L.begin();

    for (const auto &c : s)
    {
        if (c == 'L')
        {
            --it;
        }
        else if (c == 'R')
        {
            ++it;
        }
        else if (c == 'B')
        {
            it = L.erase(it);
            --it;
        }
        else
        {
            ++it;
            L.insert(it, c);
            --it;
        }
    }

    for (const auto &c : L)
    {
        cout << c;
    }
    cout << endl;

    return 0;
}