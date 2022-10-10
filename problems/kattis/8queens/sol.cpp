#include <bits/stdc++.h>

using namespace std;

bool isOnBoard(int r, int c)
{
    return 0 <= r && r < 8 && 0 <= c && c < 8;
}

bool isCollisionFree(const vector<vector<char>> &board, int r, int c)
{
    vector<int> ro = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> co = {-1, 0, 1, -1, 1, -1, 0, 1};

    int _r = r;
    int _c = c;
    for (int i = 0; i < ro.size(); ++i)
    {
        r = _r;
        c = _c;
        while (true)
        {
            r += ro[i];
            c += co[i];

            if (!isOnBoard(r, c))
                break;

            if (board[r][c] == '*')
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    vector<vector<char>> board(8, vector<char>(8, '.'));

    int count = 0;
    for (int r = 0; r < 8; ++r)
        for (int c = 0; c < 8; ++c)
        {
            cin >> board[r][c];
            if (board[r][c] == '*')
                ++count;
        }

    if (count != 8)
    {
        cout << "invalid" << endl;
        return 0;
    }

    for (int r = 0; r < 8; ++r)
        for (int c = 0; c < 8; ++c)
        {
            if (board[r][c] == '*' && !isCollisionFree(board, r, c))
            {
                cout << "invalid" << endl;
                return 0;
            }
        }

    cout << "valid" << endl;
    return 0;
}