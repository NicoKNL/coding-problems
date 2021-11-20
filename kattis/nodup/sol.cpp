#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    int spaces = 0;
    for (const auto &c : s)
    {
        if (c == ' ')
            ++spaces;
    }

    stringstream ss;
    ss.str(s);

    map<string, int> M;
    for (int i = 0; i < spaces + 1; ++i)
    {
        string tmp;
        ss >> tmp;

        ++M[tmp];

        if (M[tmp] > 1)
        {
            cout << "no" << endl;

            return 0;
        }
    }

    cout << "yes" << endl;

    return 0;
}