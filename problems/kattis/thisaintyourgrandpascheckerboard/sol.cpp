#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<vector<char>> Board;

bool rowCountOK(const Board &board)
{
    int n = board.size();

    for (int r = 0; r < n; ++r)
    {
        int b_count = count(board[r].begin(), board[r].end(), 'B');
        int w_count = count(board[r].begin(), board[r].end(), 'W');

        if (b_count != w_count)
            return false;
    }

    return true;
}

bool rowSplitOK(const Board &board)
{
    int n = board.size();

    for (int r = 0; r < n; ++r)
    {
        int len = 0;
        char cur = '.';
        for (int c = 0; c < n; ++c)
        {
            if (board[r][c] != cur)
            {
                cur = board[r][c];
                len = 1;
            }
            else
            {
                ++len;
            }

            if (len >= 3)
                return false;
        }
    }
    return true;
}

Board rotateBoard(const Board &board)
{
    Board new_board = board;
    int n = new_board.size();
    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < n; ++c)
        {
            new_board[n - c - 1][r] = board[r][c];
        }
    }
    return new_board;
}

bool columnCountOK(const Board &board)
{
    int n = board.size();
    Board rotated_board = rotateBoard(board);
    return rowCountOK(rotated_board);
}

bool columnSplitOK(const Board &board)
{
    int n = board.size();
    Board rotated_board = rotateBoard(board);
    return rowSplitOK(rotated_board);
}

int main()
{
    int n;
    cin >> n;

    Board board(n, vector<char>(n, '.'));

    for (int r = 0; r < n; ++r)
        for (int c = 0; c < n; ++c)
            cin >> board[r][c];

    if (rowCountOK(board) && columnCountOK(board) && rowSplitOK(board) && columnSplitOK(board))
        cout << 1 << endl;
    else
        cout << 0 << endl;
}