#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    while (n--)
    {
        string s;
        getline(cin, s);

        vector<int> V(26, 0);

        for (char c : s)
        {
            c = tolower(c);
            if ('a' <= c && c <= 'z')
                V[c - 'a'] = 1;
        }

        int result = accumulate(V.begin(), V.end(), 0);
        if (result == 26)
        {
            cout << "pangram" << endl;
        }
        else
        {
            cout << "missing ";

            for (int i = 0; i < 26; ++i)
                if (V[i] == 0)
                    cout << (char)('a' + i);

            cout << endl;
        }
    }
    return 0;
}