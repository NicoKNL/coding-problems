#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int wins = 0;

    while (n--)
    {
        string s;
        cin >> s;

        bool win = true;
        for (int i = 1; i < s.length(); ++i)
        {
            char current = s[i];

            if (s[i - 1] == 'C' && s[i] == 'D')
                win = false;
        }

        if (win)
            ++wins;
    }

    cout << wins << endl;

    return 0;
}