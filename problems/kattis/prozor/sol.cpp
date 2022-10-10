#include <iostream>
#include <vector>

using namespace std;

int flyCount(const vector<vector<char>> &window, int row, int col, int size)
{
    if (row + size > window.size())
        return 0;
    if (col + size > window[0].size())
        return 0;

    int count = 0;
    for (int r = row + 1; r < row + size - 1; ++r)
        for (int c = col + 1; c < col + size - 1; ++c)
            if (window[r][c] == '*')
                ++count;

    return count;
}

void drawSwatter(vector<vector<char>> &window, int row, int col, int size)
{
    window[row][col] = '+';
    window[row + size - 1][col] = '+';
    window[row][col + size - 1] = '+';
    window[row + size - 1][col + size - 1] = '+';

    for (int r = row + 1; r < row + size - 1; ++r)
    {
        window[r][col] = '|';
        window[r][col + size - 1] = '|';
    }

    for (int c = col + 1; c < col + size - 1; ++c)
    {
        window[row][c] = '-';
        window[row + size - 1][c] = '-';
    }

    for (int r = 0; r < window.size(); ++r)
    {
        for (int c = 0; c < window[0].size(); ++c)
        {
            cout << window[r][c];
        }
        cout << '\n';
    }
    cout << '\n';
}

int main()
{
    int R, S, K;
    cin >> R >> S >> K;

    vector<vector<char>> window(R, vector<char>(S, '.'));

    for (int r = 0; r < R; ++r)
        for (int c = 0; c < S; ++c)
            cin >> window[r][c];

    int count = 0;
    int best_r = 0, best_c = 0;
    for (int r = 0; r < R; ++r)
        for (int c = 0; c < S; ++c)
        {
            int current_count = flyCount(window, r, c, K);
            if (current_count > count)
            {
                best_r = r;
                best_c = c;
                count = current_count;
            }
        }

    cout << count << '\n';
    drawSwatter(window, best_r, best_c, K);
    return 0;
}