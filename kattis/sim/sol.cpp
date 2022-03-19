#include <bits/stdc++.h>

using namespace std;

list<char>::iterator backspace(list<char> &L, list<char>::iterator it)
{
    if (it == L.begin())
        return it;
    else if (it == L.end())
    {
        L.pop_back();
        return L.end();
    }
    else
    {
        --it;
        return L.erase(it);
    }
}

list<char>::iterator insert_character(list<char> &L, list<char>::iterator it, char c)
{
    if (it == L.begin())
    {
        L.push_front(c);
        it = L.begin();
    }
    else if (it == L.end())
    {
        L.push_back(c);
        return L.end();
    }
    else
    {
        it = L.insert(it, c);
    }
    ++it;
    return it;
}

void solve()
{
    string s;
    getline(cin, s);

    list<char> L;
    auto it = L.begin();
    for (const char &c : s)
    {
        if (c == '<')
        {
            it = backspace(L, it);
        }
        else if (c == '[')
        {
            it = L.begin();
        }
        else if (c == ']')
        {
            it = L.end();
        }
        else
        {
            it = insert_character(L, it, c);
        }
    }

    for (const auto &c : L)
        cout << c;
    cout << endl;
}

int main()
{
    int T;
    cin >> T;
    cin.ignore(); // ignore newline
    while (T--)
    {
        solve();
    }
    return 0;
}