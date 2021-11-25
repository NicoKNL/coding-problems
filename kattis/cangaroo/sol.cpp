#include <bits/stdc++.h>

using namespace std;

bool isValid(unsigned int n)
{
    unsigned int mask = 0b11;

    while (n)
    {
        if ((n & mask) == 3)
        {
            return false;
        }

        n >>= 1;
    }

    return true;
}

vector<unsigned int> generatePositions(int w)
{
    vector<unsigned int> V;

    for (unsigned int i = 0; i < (1 << w); ++i)
        if (isValid(i))
            V.push_back(i);

    return V;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<unsigned int> positions = generatePositions(m - 1);

    for (const auto &p : positions)
    {
        cout << bitset<10>(p) << endl;
    }

    vector<vector<char>> grid(n, vector<char>(m, '.'));

    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < m; ++c)
        {
            cin >> grid[r][c];
        }
    }

    // TODO: DP

    return 0;
}