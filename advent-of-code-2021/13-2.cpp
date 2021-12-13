#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> Point;
#define x first
#define y second

typedef pair<char, int> Fold;
#define dir first
#define pos second

ostream &operator<<(ostream &os, vector<vector<char>> &V)
{
    for (int r = 0; r < V.size(); ++r)
    {
        for (int c = 0; c < V[0].size(); ++c)
        {
            os << V[r][c];
        }
        os << endl;
    }
    os << endl;
    return os;
}

Point parseLine(string s)
{
    stringstream ss;
    ss << s;
    int x, y;
    char c;
    ss >> x >> c >> y;
    return {x, y};
}

Fold parseFold(string s)
{
    stringstream ss;
    ss << s;
    int pos;
    char dir, _;
    string tmp;
    ss >> tmp >> tmp >> dir >> _ >> pos;
    return {dir, pos};
}

void foldLeft(vector<vector<char>> &P, int pos)
{
    vector<vector<char>> next_P;

    int s = 2 * pos + 1;
    for (int r = 0; r < P.size(); ++r)
    {
        vector<char> row;
        for (int c = 0; c < pos; ++c)
        {
            if (P[r][c] == '#' || P[r][s - c - 1] == '#')
                row.push_back('#');
            else
                row.push_back('.');
        }
        next_P.push_back(row);
    }

    P = next_P;
}

void foldUp(vector<vector<char>> &P, int pos)
{
    vector<vector<char>> next_P;

    int s = 2 * pos + 1;
    for (int r = 0; r < pos; ++r)
    {
        vector<char> row;
        for (int c = 0; c < P[0].size(); ++c)
        {
            if (P[r][c] == '#' || P[s - r - 1][c] == '#')
                row.push_back('#');
            else
                row.push_back('.');
        }
        next_P.push_back(row);
    }

    P = next_P;
}

int countPointsAfterFolding(vector<vector<char>> &P, vector<Fold> &F)
{
    for (const auto &f : F)
    {
        if (f.dir == 'x')
            foldLeft(P, f.pos);
        else
            foldUp(P, f.pos);
    }

    int count = 0;
    for (int r = 0; r < P.size(); ++r)
    {
        for (int c = 0; c < P[0].size(); ++c)
        {
            if (P[r][c] == '#')
                ++count;
        }
    }
    return count;
}

int main()
{
    int MAX = 0;

    // parse points
    vector<Point> P;
    string line;
    while (getline(cin, line))
    {
        if (line.length() == 0)
        {
            break;
        }

        Point p = parseLine(line);

        MAX = max(MAX, p.x);
        MAX = max(MAX, p.y);

        P.push_back(p);
    }

    vector<vector<char>> V(MAX + 1, vector<char>(MAX + 1, '.'));

    for (const auto &p : P)
        V[p.y][p.x] = '#';

    // parse commands
    vector<Fold> F;
    while (getline(cin, line))
    {
        Fold f = parseFold(line);
        F.push_back(f);
    }
    countPointsAfterFolding(V, F);
    cout << V << endl;

    return 0;
}