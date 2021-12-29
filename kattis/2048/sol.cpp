#include <bits/stdc++.h>

using namespace std;

ostream &operator<<(ostream &os, const vector<vector<int>> &G)
{
    for (int r = 0; r < 4; ++r)
    {
        for (int c = 0; c < 4; ++c)
        {
            if (c > 0)
                os << " ";

            os << G[r][c];
        }
        os << endl;
    }
    return os;
}

void shiftLeft(vector<vector<int>> &G)
{
    vector<vector<bool>> locked(4, vector<bool>(4, false));

    for (int i = 0; i < 3; ++i)
        for (int r = 0; r < 4; ++r)
        {
            for (int c = 1; c < 4; ++c)
            {
                if (G[r][c] == G[r][c - 1] && !locked[r][c - 1] && !locked[r][c])
                {
                    G[r][c] = 0;
                    G[r][c - 1] = 2 * G[r][c - 1];
                    locked[r][c - 1] = true;
                }
                else if (G[r][c - 1] == 0)
                {
                    G[r][c - 1] = G[r][c];
                    G[r][c] = 0;
                    locked[r][c - 1] = locked[r][c];
                    locked[r][c] = false;
                }
            }
        }
}

void shiftUp(vector<vector<int>> &G)
{
    vector<vector<bool>> locked(4, vector<bool>(4, false));

    for (int i = 0; i < 3; ++i)
        for (int c = 0; c < 4; ++c)
        {
            for (int r = 1; r < 4; ++r)
            {
                if (G[r][c] == G[r - 1][c] && !locked[r - 1][c] && !locked[r][c])
                {
                    G[r][c] = 0;
                    G[r - 1][c] = 2 * G[r - 1][c];
                    locked[r - 1][c] = true;
                }
                else if (G[r - 1][c] == 0)
                {
                    G[r - 1][c] = G[r][c];
                    G[r][c] = 0;
                    locked[r - 1][c] = locked[r][c];
                    locked[r][c] = false;
                }
            }
        }
}

void shiftRight(vector<vector<int>> &G)
{
    vector<vector<bool>> locked(4, vector<bool>(4, false));

    for (int i = 0; i < 3; ++i)
        for (int r = 0; r < 4; ++r)
        {
            for (int c = 2; c >= 0; --c)
            {
                if (G[r][c] == G[r][c + 1] && !locked[r][c + 1] && !locked[r][c])
                {
                    G[r][c] = 0;
                    G[r][c + 1] = 2 * G[r][c + 1];
                    locked[r][c + 1] = true;
                }
                else if (G[r][c + 1] == 0)
                {
                    G[r][c + 1] = G[r][c];
                    G[r][c] = 0;
                    locked[r][c + 1] = locked[r][c];
                    locked[r][c] = false;
                }
            }
        }
}

void shiftDown(vector<vector<int>> &G)
{
    vector<vector<bool>> locked(4, vector<bool>(4, false));

    for (int i = 0; i < 3; ++i)
        for (int c = 0; c < 4; ++c)
        {
            for (int r = 2; r >= 0; --r)
            {
                if (G[r][c] == G[r + 1][c] && !locked[r + 1][c] && !locked[r][c])
                {
                    G[r][c] = 0;
                    G[r + 1][c] = 2 * G[r + 1][c];
                    locked[r + 1][c] = true;
                }
                else if (G[r + 1][c] == 0)
                {
                    G[r + 1][c] = G[r][c];
                    G[r][c] = 0;
                    locked[r + 1][c] = locked[r][c];
                    locked[r][c] = false;
                }
            }
        }
}

int main()
{
    vector<vector<int>> G(4, vector<int>(4, 0));

    for (int r = 0; r < 4; ++r)
        for (int c = 0; c < 4; ++c)
            cin >> G[r][c];
    int dir;
    cin >> dir;

    vector<void (*)(vector<vector<int>> &)> mapping = {
        shiftLeft,
        shiftUp,
        shiftRight,
        shiftDown,
    };

    mapping[dir](G);

    cout << G;
    return 0;
}