#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int A = 0;
    int B = 0;
    for (int i = 0; i < s.length() - 1; i += 2)
    {
        if (s[i] == 'A')
        {
            A += s[i + 1] - '0';
        }
        else
        {
            B += s[i + 1] - '0';
        }
    }

    if (A > B)
        cout << "A" << endl;
    else
        cout << "B" << endl;

    return 0;
}