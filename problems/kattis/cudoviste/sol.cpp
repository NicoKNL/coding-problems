#include <bits/stdc++.h>

using namespace std;

ostream &operator<<(ostream &os, const vector<vector<char>> &V)
{
    for (int r = 0; r < V.size(); ++r)
    {
        for (int c = 0; c < V[0].size(); ++c)
        {
            cout << V[r][c];
        }
        cout << endl;
    }

    return os;
}

int main()
{
    int R, C;
    cin >> R >> C;

    vector<vector<char>> V(R, vector<char>(C, '.'));

    for (int r = 0; r < R; ++r)
    {
        for (int c = 0; c < C; ++c)
        {
            cin >> V[r][c];
        }
    }

    vector<int> counter(5, 0);

    for (int r = 0; r < R - 1; ++r)
    {
        for (int c = 0; c < C - 1; ++c)
        {
            int sum = 0;

            if (V[r][c] == '#')
                continue;
            if (V[r + 1][c] == '#')
                continue;
            if (V[r][c + 1] == '#')
                continue;
            if (V[r + 1][c + 1] == '#')
                continue;

            if (V[r][c] == 'X')
                ++sum;
            if (V[r + 1][c] == 'X')
                ++sum;
            if (V[r][c + 1] == 'X')
                ++sum;
            if (V[r + 1][c + 1] == 'X')
                ++sum;

            ++counter[sum];
        }
    }

    for (const auto &count : counter)
    {
        cout << count << endl;
    }

    return 0;
}