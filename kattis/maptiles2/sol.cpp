#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int r = 0;
    int c = 0;

    for (char c_ : s)
    {
        r *= 2;
        c *= 2;

        if (c_ == '0')
        {
            continue;
        }
        else if (c_ == '1')
        {
            ++c;
        }
        else if (c_ == '2')
        {
            ++r;
        }
        else
        { // c == '3'
            ++r;
            ++c;
        }
    }

    int level = s.length();

    cout << level << " " << c << " " << r << endl;

    return 0;
}