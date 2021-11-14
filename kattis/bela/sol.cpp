#include <bits/stdc++.h>

using namespace std;

struct Card
{
    char suit;
    char value;

    Card(string s)
    {
        this->value = s[0];
        this->suit = s[1];
    }
};

map<char, int> D = {
    {'A', 11},
    {'K', 4},
    {'Q', 3},
    {'J', 20},
    {'T', 10},
    {'9', 14},
    {'8', 0},
    {'7', 0}};

map<char, int> ND = {
    {'A', 11},
    {'K', 4},
    {'Q', 3},
    {'J', 2},
    {'T', 10},
    {'9', 0},
    {'8', 0},
    {'7', 0}};

int main()
{
    int N;
    char dominant;

    cin >> N >> dominant;

    int score = 0;
    for (size_t i = 0; i < 4 * N; i++)
    {
        string s;
        cin >> s;
        Card c(s);

        if (c.suit == dominant)
        {
            score += D[c.value];
        }
        else
        {
            score += ND[c.value];
        }
    }
    cout << score << endl;

    return 0;
}