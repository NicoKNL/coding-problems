#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    stringstream ss;
    ss.str(s);

    int n;
    ss >> n;

    vector<string> result;

    while (n--)
    {
        getline(cin, s);

        string needle = "Simon says ";

        if (s.find(needle, 0) == 0)
        {
            cout << s.substr(needle.length()) << endl;
        }
    }
}