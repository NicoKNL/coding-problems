#include <bits/stdc++.h>

using namespace std;

string lowercase(string s)
{
    string result;

    for (char c : s)
        result += tolower(c);

    return result;
}

int main()
{
    unordered_set<string> S;

    string line;
    while (getline(cin, line))
    {
        if (line.length() == 0)
            break;

        stringstream ss;
        ss << line;

        string w;
        bool first = true;
        while (ss >> w)
        {
            if (!first)
                cout << " ";

            first = false;

            string w_ = lowercase(w);

            if (S.find(w_) != S.end())
                cout << ".";
            else
                cout << w;

            S.insert(w_);
        }
        cout << endl;
    }
    return 0;
}