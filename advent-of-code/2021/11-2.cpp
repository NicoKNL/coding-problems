#include <bits/stdc++.h>

using namespace std;
#define SIZE 10
struct Octo
{
    int value;
    bool can_flash = true;
    int flash_count = 0;

    Octo(char c)
    {
        value = c - '0';
    }

    bool flash()
    {
        if (can_flash && value > 9)
        {
            ++flash_count;
            can_flash = false;
            return true;
        }
        return false;
    }

    int resetFlash()
    {
        if (!can_flash)
        {
            value = 0;
            can_flash = true;
            return 1;
        }
        else
        {
            can_flash = true;
            return 0;
        }
    }
};

typedef vector<vector<Octo>> OctoGrid;

ostream &operator<<(ostream &os, const OctoGrid &V)
{
    for (int r = 0; r < SIZE; ++r)
    {
        for (int c = 0; c < SIZE; ++c)
        {
            os << V[r][c].value;
        }
        os << endl;
    }
    os << endl;
    return os;
}

pair<int, int> operator+(const pair<int, int> &a, const pair<int, int> &b)
{
    return {a.first + b.first, a.second + b.second};
}

int resetAll(OctoGrid &V)
{
    int count = 0;
    for (int r = 0; r < SIZE; ++r)
        for (int c = 0; c < SIZE; ++c)
            count += V[r][c].resetFlash();

    return count;
}

void plusplus(OctoGrid &V)
{
    for (int r = 0; r < SIZE; ++r)
        for (int c = 0; c < SIZE; ++c)
            ++V[r][c].value;
}

bool inBounds(const pair<int, int> &pos)
{
    bool row_is_in_bounds = (0 <= pos.first) && (pos.first < SIZE);
    bool col_is_in_bounds = (0 <= pos.second) && (pos.second < SIZE);

    return row_is_in_bounds && col_is_in_bounds;
}

void plusplusAdjacent(OctoGrid &V, set<pair<int, int>> &S)
{
    vector<pair<int, int>> offsets = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (const auto &pos : S)
    {
        for (const auto &o : offsets)
        {
            pair<int, int> adj = pos + o;
            if (inBounds(adj))
            {
                ++V[adj.first][adj.second].value;
            }
        }
    }
}

void step(OctoGrid &V)
{
    bool changed = true;
    while (changed)
    {
        changed = false;
        set<pair<int, int>> flashes;

        for (int r = 0; r < SIZE; ++r)
            for (int c = 0; c < SIZE; ++c)
            {
                bool has_flashed = V[r][c].flash();

                if (has_flashed)
                {
                    flashes.insert({r, c});
                    changed = true;
                }
            }

        plusplusAdjacent(V, flashes);
    }
}

int count(OctoGrid &V)
{
    int count = 0;
    for (int r = 0; r < SIZE; ++r)
        for (int c = 0; c < SIZE; ++c)
            count += V[r][c].flash_count;
    return count;
}

int main()
{
    vector<vector<Octo>> V(SIZE, vector<Octo>(SIZE, '0'));

    for (int r = 0; r < SIZE; ++r)
    {
        for (int c = 0; c < SIZE; ++c)
        {
            char ch;
            cin >> ch;
            V[r][c] = Octo(ch);
        }
    }

    cout << V << endl;

    for (int i = 1;; ++i)
    {
        plusplus(V);
        step(V);
        int count = resetAll(V);
        if (count == 100)
        {
            cout << i << endl;
            return 0;
        }
        cout << V << endl;
    }

    cout << count(V) << endl;

    return 0;
}