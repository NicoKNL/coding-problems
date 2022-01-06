#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_set<string> S;

    while (n--)
    {
        string op, name;
        cin >> op >> name;

        if (S.find(name) != S.end())
        {
            if (op == "entry")
            {
                cout << name << " entered (ANOMALY)" << endl;
            }
            else
            {
                cout << name << " exited" << endl;
                S.erase(name);
            }
        }
        else
        {
            if (op == "entry")
            {
                cout << name << " entered" << endl;
                S.insert(name);
            }
            else
            {
                cout << name << " exited (ANOMALY)" << endl;
            }
        }
    }

    return 0;
}