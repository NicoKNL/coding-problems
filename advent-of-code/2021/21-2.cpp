#include <bits/stdc++.h>

using namespace std;

void roll(int &dice, int &rolls)
{
    ++rolls;
    ++dice;
    if (dice > 100)
        dice = 1;
}

struct Player
{
    int score;
    int pos;

    Player()
    {
        pos = 0;
        score = 0;
    }

    Player(int p)
    {
        pos = p;
        score = 0;
    }

    void move(int positions)
    {
        for (int i = 0; i < positions; ++i)
        {
            ++pos;
            if (pos == 11)
                pos = 1;
        }

        score += pos;
    }
};

struct Game
{
    Player p1;
    Player p2;

    Game(int a, int b)
    {
        p1 = Player(a);
        p2 = Player(b);
    }
};

void dfs(Game g, int roll1, int roll2, unsigned long long &wins1, unsigned long long &wins2)
{
    g.p1.move(roll1);

    if (g.p1.score >= 21)
    {
        ++wins1;
        return;
    }

    g.p2.move(roll2);

    if (g.p2.score >= 21)
    {
        ++wins2;
        return;
    }

    for (int _ = 0; _ < 3; ++_)
    {
        for (int __ = 0; __ < 3; ++__)
        {

            for (int i = 1; i <= 3; ++i)
            {
                for (int ii = 1; ii <= 3; ++ii)
                {
                    dfs(g, i, ii, wins1, wins2);
                }
            }
        }
    }
}

int main()
{
    int start_a, start_b;
    cin >> start_a >> start_b;

    Game g(start_a, start_b);

    unsigned long long wins1 = 0;
    unsigned long long wins2 = 0;

    for (int i = 1; i <= 3; ++i)
    {
        for (int ii = 1; ii <= 3; ++ii)
        {
            dfs(g, i, ii, wins1, wins2);
        }
    }

    unsigned long long max_wins = max(wins1, wins2);
    cout << max_wins << endl;
    return 0;
}