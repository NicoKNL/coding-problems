#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<int> cups = {-1, 1, 0, 0};

    for (char &c : s)
    {
        if (c == 'A')
        {
            swap(cups[1], cups[2]);
        }
        else if (c == 'B')
        {
            swap(cups[2], cups[3]);
        }
        else if (c == 'C')
        {
            swap(cups[1], cups[3]);
        }
    }

    for (int i = 0; i < 4; ++i)
    {
        if (cups[i] == 1)
        {
            cout << i << endl;
        }
    }

    return 0;
}