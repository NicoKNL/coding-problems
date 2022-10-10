#include <bits/stdc++.h>

using namespace std;

int main()
{
    fixed(cout);
    cout.precision(9);

    string s;
    cin >> s;

    double whitespace = 0;
    double lowercase = 0;
    double uppercase = 0;
    double symbols = 0;

    for (const auto &c : s)
    {
        if (c == '_')
        {
            whitespace += 1;
        }
        else if ('a' <= c && c <= 'z')
        {
            lowercase += 1;
        }
        else if ('A' <= c && c <= 'Z')
        {
            uppercase += 1;
        }
        else
        {
            symbols += 1;
        }
    }

    cout << whitespace / (double)s.length() << endl;
    cout << lowercase / (double)s.length() << endl;
    cout << uppercase / (double)s.length() << endl;
    cout << symbols / (double)s.length() << endl;

    return 0;
}