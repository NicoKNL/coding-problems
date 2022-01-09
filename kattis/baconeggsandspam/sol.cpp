#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        cin.ignore();

        map<string, set<string>> M;

        while (n--)
        {
            string line;
            getline(cin, line);
            stringstream ss;
            ss << line;

            string name;
            ss >> name;

            string item;
            while (ss >> item)
            {
                M[item].insert(name);
            }
        }

        for (auto each : M)
        {
            cout << each.first;

            for (auto name : each.second)
            {
                cout << " " << name;
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}