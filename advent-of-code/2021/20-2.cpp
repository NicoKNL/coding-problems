#include <bits/stdc++.h>

using namespace std;
#define PADDING 150

ostream &operator<<(ostream &os, const vector<string> &V)
{
    for (const string &s : V)
    {
        os << s << endl;
    }
    os << endl;
    return os;
}

vector<string> createGrid()
{
    string base(3 * PADDING, '.');
    vector<string> V(3 * PADDING, base);
    return V;
}

int getIndex(string s)
{
    reverse(s.begin(), s.end());
    int index = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '#')
            index += (1 << i);
    }
    return index;
}

char applyMap(const vector<string> &V, const string &M, int r, int c)
{
    vector<pair<int, int>> offsets = {
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, -1},
        {0, 0},
        {0, 1},
        {1, -1},
        {1, 0},
        {1, 1}};

    string code = "";
    for (int i = 0; i < offsets.size(); ++i)
    {
        int ro = offsets[i].first;
        int co = offsets[i].second;

        code += V[r + ro][c + co];
    }

    int index = getIndex(code);
    return M[index];
}

vector<string> step(const vector<string> &V, const string &M)
{
    vector<string> next_V = createGrid();

    for (int r = 1; r < V.size() - 1; ++r)
    {
        for (int c = 1; c < V[0].size() - 1; ++c)
        {
            next_V[r][c] = applyMap(V, M, r, c);
        }
    }

    return next_V;
}

int main()
{
    string line;
    string M;
    while (getline(cin, line))
    {
        if (line.length() == 0)
            break;

        M = line;
    }

    vector<string> V = createGrid();

    int r = PADDING;
    while (getline(cin, line))
    {
        if (line.length() == 0)
            break;

        for (int i = 0; i < line.length(); ++i)
        {
            V[r][PADDING + i] = line[i];
        }
        ++r;
    }

    cout << V << endl;
    int steps = 50;
    for (int i = 0; i < steps; ++i)
        V = step(V, M);

    cout << V << endl;

    int count = 0;
    for (int r = steps; r < V.size() - steps; ++r)
    {
        for (int c = steps; c < V[0].size() - steps; ++c)
        {
            if (V[r][c] == '#')
                ++count;
        }
    }
    cout << count << endl;

    return 0;
}