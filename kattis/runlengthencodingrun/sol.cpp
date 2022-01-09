#include <bits/stdc++.h>

using namespace std;

void encode(string s)
{
    string result;

    char prev = '?';
    int count = 0;

    for (char c : s)
    {
        if (prev == '?')
        {
            result += c;
            prev = c;
            count = 1;
        }
        else if (c == prev)
            ++count;
        else
        {
            result += to_string(count);
            result += c;
            prev = c;
            count = 1;
        }
    }

    result += to_string(count);
    cout << result << endl;
}

void decode(string s)
{
    vector<string> parts;
    string num;
    for (char c : s)
    {
        if ('0' <= c && c <= '9')
            num += c;
        else
        {
            if (num.length() > 0)
                parts.push_back(num);

            string tmp;
            tmp += c;
            parts.push_back(tmp);
            num = "";
        }
    }

    parts.push_back(num);

    string result;
    for (int i = 0; i < parts.size(); i += 2)
    {
        int count = stoi(parts[i + 1]);
        while (count--)
        {
            result += parts[i];
        }
    }

    cout << result << endl;
}

int main()
{
    char mode;
    cin >> mode;

    string message;
    cin >> message;

    if (mode == 'E')
        encode(message);
    else // mode == 'D'
        decode(message);

    return 0;
}