#include <bits/stdc++.h>

using namespace std;

map<char, int> M = {
    {')', 3},
    {']', 57},
    {'}', 1197},
    {'>', 25137}};

map<char, unsigned long long> M2 = {
    {'(', 1},
    {'[', 2},
    {'{', 3},
    {'<', 4}};

int main()
{
    string s;
    vector<unsigned long long> scores;
    while (getline(cin, s))
    {
        if (s.length() == 0)
            break;

        unsigned long long score = 0;
        stack<char> S;

        bool illegal = false;
        for (const auto &c : s)
        {
            if (c == '(' || c == '[' || c == '{' || c == '<')
                S.push(c);
            else
            {
                char other = S.top();
                if (c == ')')
                {
                    if (other == '(')
                        S.pop();
                    else
                        illegal = true;
                }
                else if (c == ']')
                {
                    if (other == '[')
                        S.pop();
                    else
                        illegal = true;
                }
                else if (c == '}')
                {
                    if (other == '{')
                        S.pop();
                    else
                        illegal = true;
                }
                else
                { // c == '>'
                    if (other == '<')
                        S.pop();
                    else
                        illegal = true;
                }

                if (illegal)
                {
                    // score += M[c];
                    break;
                }
            }
        }

        if (!illegal)
        {
            while (!S.empty())
            {
                char other = S.top();
                S.pop();

                score *= (unsigned long long)5;
                score += M2[other];
            }
            scores.push_back(score);
        }
    }
    sort(scores.begin(), scores.end());

    cout << scores[scores.size() / 2] << endl;

    return 0;
}