#include <bits/stdc++.h>

using namespace std;

int NROWS = 0;
int NCOLS = 0;
int SOLUTIONS = 0;

vector<vector<int>> G;
vector<unordered_map<int, int>> M;
vector<vector<int>> check;
map<tuple<int, int, int>, set<int>> valid_picks;

ostream &operator<<(ostream &os, const vector<vector<int>> &G)
{
    for (int r = 0; r < NROWS; ++r)
    {
        for (int c = 0; c < NCOLS; ++c)
        {
            os << G[r][c] << " ";
        }
        os << endl;
    }
    return os;
}

pair<int, int> next(int r, int c)
{
    if (c == 0)
        return {r + 1, NCOLS - 1};

    return {r, c - 1};
}

bool isDuplicated(unordered_map<int, int> &M, int v)
{
    return M[v] > 0;
}

bool isQuotient(int l, int u, int r)
{
    if (l < r)
        swap(l, r);

    if (l % r == 0)
    {
        return l / r == u;
    }

    return false;
}

bool isValidTuple(tuple<int, int, int> &t)
{
    auto &[u, l, r] = t;

    if (l * r == u)
        return true;

    if (l + r == u)
        return true;

    if (abs(l - r) == u)
        return true;

    if (isQuotient(l, u, r))
        return true;

    return false;
}

bool isValid(int r, int c)
{
    if (r == 0 || c == NCOLS - 1)
        return true;

    int u_ = G[r - 1][c];
    int l_ = G[r][c];
    int r_ = G[r][c + 1];

    tuple<int, int, int> t = {u_, l_, r_};

    if (valid_picks.find(t) != valid_picks.end())
        return true;

    return isValidTuple(t);
}

pair<bool, int> hasSingleZero(const tuple<int, int, int> &t)
{
    int zeroes = 0;
    int i = 0;

    if (get<0>(t) == 0)
    {
        ++zeroes;
        i = 0;
    }

    if (get<1>(t) == 0)
    {
        ++zeroes;
        i = 1;
    }

    if (get<2>(t) == 0)
    {
        ++zeroes;
        i = 2;
    }

    return {zeroes == 1, i};
}

void prepass(int iterations)
{
    for (int i = 0; i < iterations; ++i)
    {
        for (int r = 0; r < NROWS; ++r)
        {
            for (int c = 0; c < NCOLS; ++c)
            {
                if (r == 0 || c == NCOLS - 1)
                    continue;

                int u_ = G[r - 1][c];
                int l_ = G[r][c];
                int r_ = G[r][c + 1];

                tuple<int, int, int> t = {u_, l_, r_};
                // cout << "<" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << "> " << valid_picks[t].size() << endl;

                auto [has_single_zero, i] = hasSingleZero(t);

                if (has_single_zero)
                {
                    // cout << "single zero" << endl;
                    // cout << "<" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << "> " << valid_picks[t].size() << endl;
                    if (valid_picks[t].size() == 1)
                    {
                        // cout << "FORCED PICK!" << endl;
                        int forced_pick = *valid_picks[t].begin();
                        if (i == 0)
                            G[r - 1][c] = forced_pick;

                        if (i == 1)
                            G[r][c] = forced_pick;

                        if (i == 2)
                            G[r][c + 1] = forced_pick;
                    }
                }
            }
        }
    }
}

void backtrack(int r, int c)
{
    // cout << r << " " << c << endl;
    if (r >= NROWS)
    {
        // cout << "-------" << endl;
        // cout << G;
        ++SOLUTIONS;
        return;
    }

    auto [next_r, next_c] = next(r, c);

    if (G[r][c])
    {
        if (check[r][c])
        {
            if (!isValid(r, c))
                return;
        }
        backtrack(next_r, next_c);
    }
    else
    {
        tuple<int, int, int> t;
        if (r == 0 || c == NCOLS - 1)
        {
            t = {-1, -1, -1};
        }
        else
        {
            t = {G[r - 1][c], G[r][c], G[r][c + 1]};
        }

        if (valid_picks[t].size() == 1)
        {
            int forced_pick = *valid_picks[t].begin();

            if (!isDuplicated(M[r], forced_pick))
            {
                G[r][c] = forced_pick;
                ++M[r][forced_pick];

                backtrack(next_r, next_c);

                G[r][c] = 0;
                --M[r][forced_pick];
            }
        }
        else
        {
            for (int i = 1; i <= 9; ++i)
            {
                if (isDuplicated(M[r], i))
                    continue;

                G[r][c] = i;
                ++M[r][i];

                if (isValid(r, c))
                {
                    backtrack(next_r, next_c);
                }

                G[r][c] = 0;
                --M[r][i];
            }
        }
    }
}

void buildValidPicks()
{
    for (int u = 1; u <= 9; ++u)
        for (int l = 1; l <= 9; ++l)
            for (int r = 1; r <= 9; ++r)
            {
                tuple<int, int, int> t = {u, l, r};

                // cout << "<" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ">" << endl;
                if (isValidTuple(t))
                {
                    tuple<int, int, int> t_u = {0, get<1>(t), get<2>(t)};
                    tuple<int, int, int> t_l = {get<0>(t), 0, get<2>(t)};
                    tuple<int, int, int> t_r = {get<0>(t), get<1>(t), 0};

                    valid_picks[t_u].insert(get<0>(t));
                    valid_picks[t_l].insert(get<1>(t));
                    valid_picks[t_r].insert(get<2>(t));
                }
            }
}

int main()
{
    cin >> NROWS >> NCOLS;

    G = vector<vector<int>>(NROWS, vector<int>(NCOLS, 0));
    M = vector<unordered_map<int, int>>(NROWS, unordered_map<int, int>());
    check = vector<vector<int>>(NROWS, vector<int>(NCOLS, 0));

    for (int r = 0; r < NROWS; ++r)
        for (int c = 0; c < NCOLS; ++c)
        {
            cin >> G[r][c];
            if (G[r][c] == 0)
            {
                if (r == 0 && c > 0)
                    check[r + 1][c] = 1;

                if (c > 0)
                    check[r][c - 1] = 1;

                check[r][c] = 1;
            }
            else
            {
                ++M[r][G[r][c]];
            }
        }

    // cout << "building" << endl;
    buildValidPicks();

    // cout << "================================== PREPASS =====================================" << endl;

    prepass(18);
    // cout << "================================================================================" << endl;

    // cout << "showing" << endl;

    // for (auto &each : valid_picks)
    // {
    //     cout << "<" << get<0>(each.first) << ", " << get<1>(each.first) << ", " << get<2>(each.first) << "> " << each.second.size();
    //     if (each.second.size() == 1)
    //         cout << " " << *each.second.begin();
    //     cout << endl;
    // }
    backtrack(0, NCOLS - 1);

    cout << SOLUTIONS << endl;

    return 0;
}