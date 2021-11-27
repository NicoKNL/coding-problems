#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    int n;
    cin >> n;

    if (n >= a)
    {
        cout << "A" << endl;
    }
    else if (n >= b)
    {
        cout << "B" << endl;
    }
    else if (n >= c)
    {
        cout << "C" << endl;
    }
    else if (n >= d)
    {
        cout << "D" << endl;
    }
    else if (n >= e)
    {
        cout << "E" << endl;
    }
    else
    {
        cout << "F" << endl;
    }

    return 0;
}