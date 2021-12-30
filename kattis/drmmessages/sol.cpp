#include <bits/stdc++.h>

using namespace std;

string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int getIndex(char c) { return c - 'A'; }

char rotate(char c, int distance)
{
    int i = getIndex(c);
    i += distance;
    i %= 26;

    return ABC[i];
}

pair<string, string> divide(string s)
{
    return {s.substr(0, s.length() / 2), s.substr(s.length() / 2)};
}

int sum(string s)
{
    int result = 0;

    for (char c : s)
    {
        result += getIndex(c);
    }

    return result;
}

string rotateString(string s, int distance)
{
    for (int i = 0; i < s.length(); ++i)
    {
        s[i] = rotate(s[i], distance);
    }

    return s;
}

string merge(string l, string r)
{
    for (int i = 0; i < l.length(); ++i)
    {
        l[i] = rotate(l[i], getIndex(r[i]));
    }
    return l;
}

int main()
{
    string s;
    cin >> s;

    string left, right;
    tie(left, right) = divide(s);

    int left_sum = sum(left);
    int right_sum = sum(right);

    left = rotateString(left, left_sum);
    right = rotateString(right, right_sum);

    string result = merge(left, right);

    cout << result << endl;

    return 0;
}