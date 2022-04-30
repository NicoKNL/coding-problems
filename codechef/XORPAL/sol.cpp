#include <bits/stdc++.h>

using namespace std;

string parseInput()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    return s;
}

pair<int, int> countDigits(string s)
{
    int zero = 0;
    int one = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '0')
            ++zero;
        else
            ++one;
    }

    return {zero, one};
}

bool canShuffleToPalindrome(string s)
{
    auto [zero, one] = countDigits(s);

    bool all_same = zero == s.length() || one == s.length();
    bool even_split = zero == one;
    bool both_even = zero % 2 == 0 && one % 2 == 0;

    if (s.length() % 2 == 0)
    {
        return all_same || even_split || both_even;
    }
    else
    {
        bool off_by_one = abs(zero - one) == 1 || zero == 1 || one == 1;
        bool evenish = (zero % 2) ^ (one % 2);

        return all_same || off_by_one || evenish;
    }
}

int removeFixpoints(const vector<int> &V)
{
    int index = 1;
    int inserts = 0;

    for (int i = 0; i < V.size(); ++i)
    {
        if (V[i] == index)
        {
            ++index;
            ++inserts;
        }
        ++index;
    }

    return inserts;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        string s = parseInput();

        if (canShuffleToPalindrome(s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}