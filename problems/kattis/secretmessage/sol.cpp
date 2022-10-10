#include <bits/stdc++.h>

using namespace std;

ostream &operator<<(ostream &os, vector<string> V)
{
    for (string s : V)
        os << s << endl;
    return os;
}

void rotate(vector<string> &V)
{
    vector<string> result = V;

    int nrows = V.size();
    int ncols = V.size();
    for (int r = 0; r < nrows; ++r)
    {
        for (int c = 0; c < ncols; ++c)
        {
            result[c][ncols - r - 1] = V[r][c];
        }
    }

    V = result;
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        string s;
        cin >> s;

        int i = 1;
        while (i * i < s.length())
            ++i;

        while (s.length() < i * i)
            s += "*";

        vector<string> V(i, string(i, ' '));

        for (int r = 0; r < i; ++r)
        {
            for (int c = 0; c < i; ++c)
            {
                int ci = r * i + c;
                V[r][c] = s[ci];
            }
        }

        rotate(V);

        // cout << V << endl;

        for (int r = 0; r < i; ++r)
            for (int c = 0; c < i; ++c)
                if (V[r][c] != '*')
                    cout << V[r][c];
        cout << endl;
    }

    return 0;
}