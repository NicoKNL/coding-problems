#include <iostream>
#include <vector>

using namespace std;

bool is_match(const vector<int> &base, const vector<int> &piece, int start)
{
    if (start + piece.size() > base.size())
        return false;

    int baseline = 0;
    for (int i = 0; i < piece.size(); ++i)
    {
        if (i == 0)
            baseline = base[i + start];

        if (base[i + start] != baseline + piece[i])
            return false;
    }

    return true;
}

vector<vector<vector<int>>> pieces = {
    {
        // 0 Filler because input is 1 based
    },
    {
        // 1 long piece
        {0},
        {0, 0, 0, 0},
    },
    {
        // 2 square
        {0, 0},
    },
    {
        // 3 squigly piece
        {0, 0, 1},
        {0, -1},
    },
    {
        // 4 reverse squigly piece
        {0, -1, -1},
        {0, 1},
    },
    {
        // 5 T piece
        {0, 0, 0},
        {0, -1, 0},
        {0, -1},
        {0, 1},
    },
    {
        // 6 L piece
        {0, 0, 0},
        {0, 0},
        {0, -2},
        {0, 1, 1},
    },
    {
        // 7 reverse L piece
        {0, 0, 0},
        {0, 0},
        {0, 2},
        {0, 0, -1},
    },
};

int main()
{
    int C, P;
    cin >> C >> P;

    vector<int> field(C, 0);
    for (int i = 0; i < C; ++i)
        cin >> field[i];

    int count = 0;
    for (int c = 0; c < C; ++c)
    {
        for (int i = 0; i < pieces[P].size(); ++i)
        {
            if (is_match(field, pieces[P][i], c))
                ++count;
        }
    }

    cout << count << '\n';
    return 0;
}