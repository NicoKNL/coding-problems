#include <bits/stdc++.h>

using namespace std;

ostream &operator<<(ostream &os, vector<string> &G)
{
    for (string line : G)
        cout << line << endl;
    return os;
}

int step(vector<string> &G)
{
    vector<string> next_G(G.size(), string(G[0].size(), '.'));

    int n_rows = G.size();
    int n_cols = G[0].size();

    int count = 0;
    for (int r = 0; r < n_rows; ++r)
        for (int c = 0; c < n_cols; ++c)
            if (G[r][c] == '>')
                if (G[r][(c + 1) % n_cols] == '.')
                {
                    next_G[r][(c + 1) % n_cols] = '>';
                    ++count;
                }
                else
                    next_G[r][c] = '>';

    for (int r = 0; r < n_rows; ++r)
        for (int c = 0; c < n_cols; ++c)
            if (G[r][c] == 'v')
                if (G[(r + 1) % n_rows][c] != 'v' && next_G[(r + 1) % n_rows][c] == '.')
                {
                    next_G[(r + 1) % n_rows][c] = 'v';
                    ++count;
                }
                else
                    next_G[r][c] = 'v';

    G = next_G;

    return count;
}

int main()
{
    vector<string> G;

    string line;
    while (getline(cin, line))
    {
        if (line.length() == 0)
            break;

        G.push_back(line);
    }

    int i = 1;

    while (step(G))
        ++i;

    cout << i << endl;

    return 0;
}