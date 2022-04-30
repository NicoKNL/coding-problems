#include <bits/stdc++.h>

using namespace std;

struct Cave
{
    int cost;
    int dist;
    vector<Cave *> adj;
    Cave *prev;
    bool visited;
    Cave(char c)
    {
        cost = c - '0';
        dist = INT32_MAX;
        visited = false;
    }

    Cave(int v)
    {
        cost = v;
        dist = INT32_MAX;
        visited = false;
    }
};

struct comp
{
    bool operator()(Cave *a, Cave *b)
    {
        return a->dist <= b->dist && a != b;
    }
};

ostream &
operator<<(ostream &os, vector<vector<Cave *>> C)
{
    for (int r = 0; r < C.size(); ++r)
    {
        for (int c = 0; c < C[0].size(); ++c)
        {
            os << C[r][c]->cost;
        }
        os << endl;
    }
    os << endl;
    return os;
}

string extendLine(string line)
{
    string result;
    for (int i = 0; i < 5; ++i)
    {
        for (char c : line)
        {
            int value = c - '0';
            value += i;
            if (value > 9)
                value -= 9;
            result += to_string(value);
        }
    }
    return result;
}

int main()
{
    string line;
    vector<vector<Cave *>> caves;

    while (getline(cin, line))
    {
        if (line.length() == 0)
            break;

        line = extendLine(line);
        stringstream ss;
        ss << line;

        vector<Cave *> row;
        char tmp;
        while (ss >> tmp)
        {
            row.push_back(new Cave(tmp));
        }
        caves.push_back(row);
    }

    int init_size = caves.size();
    for (int i = 1; i <= 4; ++i)
    {
        for (int r = 0; r < init_size; ++r)
        {
            vector<Cave *> row;
            for (int c = 0; c < caves[0].size(); ++c)
            {
                int v = caves[r][c]->cost;
                v += i;
                if (v > 9)
                    v -= 9;
                row.push_back(new Cave(v));
            }
            caves.push_back(row);
        }
    }

    for (int r = 0; r < caves.size(); ++r)
    {
        for (int c = 0; c < caves[0].size(); ++c)
        {
            if (r - 1 >= 0)
                caves[r - 1][c]->adj.push_back(caves[r][c]);
            if (c - 1 >= 0)
                caves[r][c - 1]->adj.push_back(caves[r][c]);
            if (r + 1 < caves.size())
                caves[r + 1][c]->adj.push_back(caves[r][c]);
            if (c + 1 < caves[0].size())
                caves[r][c + 1]->adj.push_back(caves[r][c]);
        }
    }

    set<Cave *, comp> S;
    caves[0][0]->dist = 0;
    S.insert(caves[0][0]);

    int n = caves.size() - 1;

    while (!S.empty())
    {
        Cave *u = *S.begin();
        int cost_u = u->dist;
        S.erase(S.begin());

        for (Cave *v : u->adj)
        {
            int alt = cost_u + v->cost;

            if (alt < v->dist)
            {
                S.erase(v);
                v->dist = alt;
                v->prev = u;
                S.insert(v);
            }
        }
    }

    Cave *end = *(*caves.rbegin()).rbegin();
    cout << end->dist << endl;

    return 0;
}