#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s_in;
    cin >> s_in;

    for (int i = 0; i < s_in.length(); ++i)
    {
        if (s_in[i] == 'e')
        {
            cout << "ee";
        }
        else
        {
            cout << s_in[i];
        }
    }
    cout << endl;

    return 0;
}