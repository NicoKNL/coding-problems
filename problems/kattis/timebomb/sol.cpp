#include <bits/stdc++.h>

using namespace std;

map<int, vector<string>> M = {
    {0, {
            "***",
            "* *",
            "* *",
            "* *",
            "***",
        }},
    {1, {
            "  *",
            "  *",
            "  *",
            "  *",
            "  *",
        }},
    {2, {
            "***",
            "  *",
            "***",
            "*  ",
            "***",
        }},
    {3, {
            "***",
            "  *",
            "***",
            "  *",
            "***",
        }},
    {4, {
            "* *",
            "* *",
            "***",
            "  *",
            "  *",
        }},
    {5, {
            "***",
            "*  ",
            "***",
            "  *",
            "***",
        }},
    {6, {
            "***",
            "*  ",
            "***",
            "* *",
            "***",
        }},
    {7, {
            "***",
            "  *",
            "  *",
            "  *",
            "  *",
        }},
    {8, {
            "***",
            "* *",
            "***",
            "* *",
            "***",
        }},
    {9, {
            "***",
            "* *",
            "***",
            "  *",
            "***",
        }}};

int main()
{
    vector<string> V;

    string line;

    int maxlen = 0;

    while (getline(cin, line))
    {
        maxlen = max(maxlen, (int)line.length());
        V.push_back(line);
    }

    while (maxlen % 4 != 0)
        ++maxlen;

    for_each(V.begin(), V.end(),
             [=](string &s)
             {
                 while (s.length() < maxlen)
                     s += " ";
             });

    vector<int> digits;
    for (int i = 0; i < maxlen; i += 4)
    {
        for (auto [num, sign] : M)
        {
            bool match = true;
            for (int r = 0; r < 5; ++r)
            {
                for (int c = 0; c < 3; ++c)
                    if (sign[r][c] != V[r][c + i])
                        match = false;
            }

            if (match)
                digits.push_back(num);
        }
    }

    if (digits.size() != (maxlen / 4))
        cout << "BOOM!!" << endl;
    else
    {
        int number = 0;

        reverse(digits.begin(), digits.end());

        int offset = 0;
        bool prefix = true;
        for (int i = 0; i < digits.size(); ++i)
        {
            if (prefix && digits[i] == 0)
                ++offset;
            else
            {
                prefix = false;
                number += digits[i] * pow(10, i - offset);
            }
        }

        if (number % 6 == 0)
            cout << "BEER!!" << endl;
        else
            cout << "BOOM!!" << endl;
    }

    return 0;
}