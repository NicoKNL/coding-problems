#include <bits/stdc++.h>

using namespace std;

map<char, int> M = {
    {')', 3},
    {']', 57},
    {'}', 1197},
    {'>', 25137}};

int main()
{
    string s;
    long long score = 0;
    while (getline(cin, s))
    {
        if (s.length() == 0)
            break;

        stack<char> S;

        for (const auto &c : s)
        {
            if (c == '(' || c == '[' || c == '{' || c == '<')
                S.push(c);
            else
            {
                bool illegal = false;
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
                    score += M[c];
                    break;
                }
            }
        }
    }

    cout << score << endl;

    return 0;
}