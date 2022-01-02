#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<string, string> M;

    string line;
    while (getline(cin, line))
    {
        if (line.length() == 0)
            break;

        stringstream ss;
        ss << line;

        string a, b;
        ss >> a >> b;

        M[b] = a;
    }

    while (getline(cin, line))
    {
        if (line.length() == 0)
            break;

        if (M.find(line) != M.end())
            cout << M[line] << endl;
        else
            cout << "eh" << endl;
    }

    return 0;
}