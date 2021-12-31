#include <bits/stdc++.h>

using namespace std;

unordered_map<char, string> M = {
    {'a', "@"},
    {'b', "8"},
    {'c', "("},
    {'d', "|)"},
    {'e', "3"},
    {'f', "#"},
    {'g', "6"},
    {'h', "[-]"},
    {'i', "|"},
    {'j', "_|"},
    {'k', "|<"},
    {'l', "1"},
    {'m', "[]\\/[]"},
    {'n', "[]\\[]"},
    {'o', "0"},
    {'p', "|D"},
    {'q', "(,)"},
    {'r', "|Z"},
    {'s', "$"},
    {'t', "']['"},
    {'u', "|_|"},
    {'v', "\\/"},
    {'w', "\\/\\/"},
    {'x', "}{"},
    {'y', "`/"},
    {'z', "2"},
};

int main()
{
    string s;
    getline(cin, s);

    for (char c : s)
    {
        c = tolower(c);

        if (M.find(c) != M.end())
            cout << M[c];
        else
            cout << c;
    }

    cout << endl;

    return 0;
}