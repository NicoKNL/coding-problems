#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";
    int len = ABC.length();

    while (cin >> n)
    {
        if (n == 0)
            break;

        string s;
        cin >> s;

        reverse(s.begin(), s.end());

        for (char c : s)
        {
            int pos = ABC.find(c);
            pos += n;
            pos %= len;

            cout << ABC[pos];
        }

        cout << endl;
    }
    return 0;
}