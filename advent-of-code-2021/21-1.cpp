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

int main()
{
    int start_a, start_b;
    cin >> start_a >> start_b;
    cout << "start1: " << start_a << endl;
    Player p1(start_a);
    Player p2(start_b);

    int dice = 1;
    int total_rolls = 0;

    while (p1.score < 1000 && p2.score < 1000)
    {
        int v1 = 0;
        v1 += dice;
        roll(dice, total_rolls);
        v1 += dice;
        roll(dice, total_rolls);
        v1 += dice;
        roll(dice, total_rolls);
        cout << "v1: " << v1 << endl;
        p1.move(v1);
        cout << "p1: " << p1.score << endl;

        if (p1.score >= 1000)
            break;

        int v2 = 0;
        v2 += dice;
        roll(dice, total_rolls);
        v2 += dice;
        roll(dice, total_rolls);
        v2 += dice;
        roll(dice, total_rolls);
        p2.move(v2);

        // cout << p1.score << " " << p2.score << endl;
    }

    unsigned long long rolls = total_rolls;
    unsigned long long min_score = min(p1.score, p2.score);
    cout << rolls * min_score << endl;
    return 0;
}