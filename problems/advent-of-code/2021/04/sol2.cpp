#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<vector<int>>> T;

ostream &operator<<(ostream &os, const vector<vector<int>> &grid)
{
    for (int r = 0; r < grid.size(); ++r)
    {
        cout << "[";
        for (int c = 0; c < grid[0].size(); ++c)
        {
            cout << grid[r][c] << " ";
        }
        cout << "]" << endl;
    }
    return os;
}

void pick(T &cards, T &picks, int ball)
{
    for (int i = 0; i < cards.size(); ++i)
    {
        for (int r = 0; r < 5; ++r)
        {
            for (int c = 0; c < 5; ++c)
            {
                if (cards[i][r][c] == ball)
                {
                    picks[i][r][c] = 1;
                }
            }
        }
    }
}

bool hasBingo(const vector<vector<int>> &picks)
{
    // if (picks[0][0] + picks[1][1] + picks[2][2] + picks[3][3] + picks[4][4] == 5)
    //     return true;
    // if (picks[4][0] + picks[3][1] + picks[2][2] + picks[1][3] + picks[0][4] == 5)
    //     return true;

    for (int r = 0; r < 5; ++r)
    {
        int rowsum = 0;
        int colsum = 0;
        for (int c = 0; c < 5; ++c)
        {
            rowsum += picks[r][c];
            colsum += picks[c][r];
        }
        if (rowsum == 5 || colsum == 5)
            return true;
    }

    return false;
}

void answer(const vector<vector<int>> &card, const vector<vector<int>> &picks, const int &ball)
{
    cout << "----------------------------" << endl;
    cout << card << endl
         << endl;
    cout << picks << endl
         << endl;

    cout << "BINGO on " << ball << endl;
    int sum = 0;
    for (int r = 0; r < 5; ++r)
    {
        for (int c = 0; c < 5; ++c)
        {
            if (!picks[r][c])
                sum += card[r][c];
        }
    }
    cout << "sum: " << sum << endl;
    cout << sum * ball << endl;
}

int main()
{
    string s;
    getline(cin, s);

    stringstream ss;
    ss << s;
    vector<int> balls;
    int n;
    while (ss >> n)
    {
        cout << "n: " << n << endl;
        balls.push_back(n);
    }

    vector<vector<vector<int>>> cards;
    vector<vector<int>> tmp;
    while (getline(cin, s))
    {
        if (tmp.size() == 5)
        {
            cards.push_back(tmp);
            tmp = {};
        }

        ss = stringstream();
        ss << s;
        vector<int> line;

        while (ss >> n)
        {
            line.push_back(n);
        }

        tmp.push_back(line);
        cout << tmp << endl
             << endl;
    }

    cards.push_back(tmp);

    int size = cards.size();
    vector<vector<vector<int>>> picks(size, vector<vector<int>>(5, vector<int>(5, 0)));
    cout << "# of cards: " << size << endl;
    vector<vector<int>> last_card;
    vector<vector<int>> last_picks;
    int last_ball;
    vector<int> card_already_has_bingo(cards.size(), 0);
    for (const auto &ball : balls)
    {
        cout << "ball: " << ball << endl;
        pick(cards, picks, ball);
        cout << "picked..." << endl;
        for (int i = 0; i < cards.size(); ++i)
        {
            if (!card_already_has_bingo[i])
            {
                auto card = cards[i];
                auto pick = picks[i];
                if (hasBingo(pick))
                {
                    card_already_has_bingo[i] = 1;
                    last_card = card;
                    last_picks = pick;
                    last_ball = ball;
                }
            }
        }
    }

    answer(last_card, last_picks, last_ball);
    return 0;
}