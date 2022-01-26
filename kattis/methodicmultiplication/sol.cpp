#include <bits/stdc++.h>

using namespace std;

int countS(string s)
{
    int result = 0;

    for_each(s.begin(), s.end(),
             [&](char c)
             {
                 if (c == 'S')
                     ++result;
             });

    return result;
}

int main()
{
    string x, y;
    cin >> x >> y;

    int x_n = countS(x);
    int y_n = countS(y);

    int n = x_n * y_n;
    string result;

    for (int i = 0; i < n; ++i)
        cout << "S(";

    cout << 0;

    for (int i = 0; i < n; ++i)
        cout << ")";

    cout << endl;

    return 0;
}