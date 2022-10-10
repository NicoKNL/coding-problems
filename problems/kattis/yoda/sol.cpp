#include <bits/stdc++.h>

using namespace std;

void remove_leading_zeros(string &s)
{
    int i = 0;
    for (; i < s.length(); ++i)
    {
        if (s[i] != '0')
            break;
    }

    if (i == s.length())
        s = "0";
    else
        s = s.substr(i);
}

int main()
{
    string a, b;
    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string result_a, result_b;
    for (int i = 0; i < max(a.length(), b.length()); ++i)
    {
        if (i > a.length())
            a += '0';
        if (i > b.length())
            b += '0';

        if (a[i] == b[i])
        {
            result_a += a[i];
            result_b += b[i];
        }
        else if (a[i] < b[i])
        {
            result_b += b[i];
        }
        else
        {
            result_a += a[i];
        }
    }

    reverse(result_a.begin(), result_a.end());
    reverse(result_b.begin(), result_b.end());

    if (result_a.length() == 0)
        cout << "YODA" << endl;
    else
    {
        remove_leading_zeros(result_a);
        cout << result_a << endl;
    }

    if (result_b.length() == 0)
        cout << "YODA" << endl;
    else
    {
        remove_leading_zeros(result_b);
        cout << result_b << endl;
    }

    return 0;
}