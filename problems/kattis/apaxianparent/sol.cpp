#include <bits/stdc++.h>

using namespace std;

bool isNonEVowel(char c)
{
    string vowels = "aiou";
    if (vowels.find(c) == string::npos)
        return false;
    return true;
}

int main()
{
    string Y, P;
    cin >> Y >> P;

    string end = Y.substr(Y.length() - 2);

    if (end[0] == 'e' && end[1] == 'x')
        Y = Y + P;
    else if (isNonEVowel(end[1]))
        Y = Y.substr(0, Y.length() - 1) + "ex" + P;
    else if (end[1] == 'e')
        Y = Y + "x" + P;
    else
        Y = Y + "ex" + P;

    cout << Y << endl;
    return 0;
}