#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        cout << a << endl;
        cout << b << endl;
        for (int i = 0; i < a.length(); ++i)
        {
            if (a[i] != b[i])
            {
                cout << "*";
            }
            else
            {
                cout << ".";
            }
        }
        cout << endl
             << endl;
    }
    return 0;
}