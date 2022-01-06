#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    while (n--)
    {
        string line;
        getline(cin, line);

        string needle = "simon says";

        if (line.length() > needle.length())
        {
            if (line.find(needle) == 0)
                cout << line.substr(needle.length() + 1) << endl;
        }
        else
            cout << endl;
    }

    return 0;
}