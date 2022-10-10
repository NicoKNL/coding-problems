#include <bits/stdc++.h>

using namespace std;

int count(const string &s, const char &c)
{
    int result = 0;
    for (const char &sc : s)
    {
        if (sc == c)
            ++result;
    }
    return result;
}

int main()
{
    string word, guesses;
    cin >> word >> guesses;

    int OK = 0;
    int NOK = 0;

    for (char c : guesses)
    {
        int total = count(word, c);

        if (total)
        {
            OK += total;
            if (OK == word.length())
            {
                cout << "WIN" << endl;
                return 0;
            }
        }
        else
        {
            ++NOK;
            if (NOK == 10)
            {
                cout << "LOSE" << endl;
                return 0;
            }
        }
    }
}