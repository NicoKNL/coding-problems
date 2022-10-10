#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 1D int vector
 *
 * 0 1 2 3 ... 
 */
ostream &operator<<(ostream &os, const vector<int> &V)
{
    for (int i = 0; i < V.size(); ++i)
    {
        if (i > 0)
            os << " ";
        os << V[i];
    }

    return os;
}

/**
 * @brief 2D char vector
 * 
 * abc...
 * def...
 * ... 
 */
ostream &operator<<(ostream &os, const vector<vector<char>> &G)
{
    for (int r = 0; r < G.size(); ++r)
    {
        for (int c = 0; c < G[0].size(); ++c)
            os << G[r][c];
        os << endl;
    }
    return os;
}