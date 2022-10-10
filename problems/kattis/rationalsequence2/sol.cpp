#include <bits/stdc++.h>

using namespace std;

#define p first
#define q second

typedef pair<int, int> Rational;

Rational parseRational()
{
    int p, q;
    char _;
    cin >> p >> _ >> q;
    return {p, q};
}

void answer(int k, Rational r)
{
    Rational root = {1, 1};
    Rational tmp = r;
    string sequence = "";
    int height = 0;
    while (tmp != root)
    {
        ++height;

        if (tmp.p > tmp.q)
        {
            tmp.p -= tmp.q;
            sequence += 'r';
        }
        else
        {
            tmp.q -= tmp.p;
            sequence += 'l';
        }
    }

    reverse(sequence.begin(), sequence.end());

    int pos = 1;
    for (const auto &c : sequence)
    {
        if (c == 'l')
        {
            pos = 2 * pos - 1;
        }
        else
        {
            pos = 2 * pos;
        }
    }

    long long nodes_above_height;
    if (height == 0)
    {
        nodes_above_height = 0;
    }
    else
    {
        nodes_above_height = (2 << (height - 1)) - 1;
    }

    cout << k << " " << nodes_above_height + pos << endl;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int k;
        cin >> k;
        Rational r = parseRational();
        answer(k, r);
    }

    return 0;
}