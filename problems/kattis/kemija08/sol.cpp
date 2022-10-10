#include <bits/stdc++.h>

using namespace std;

bool isVowel(char c)
{
    string vowels = "aeiou";

    if (vowels.find(c) != string::npos)
    {
        return true;
    }

    return false;
}

int main()
{

    string line;
    getline(cin, line);

    string result;

    for (int i = 0; i < line.length(); ++i)
    {
        result += line[i];

        if (isVowel(line[i]))
            i += 2;
    }

    cout << result << endl;

    return 0;
}