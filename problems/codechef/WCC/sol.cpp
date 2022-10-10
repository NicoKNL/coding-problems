#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int x;
        string s;
        cin >> x >> s;

        int carlsen = 0;
        int chef = 0;

        for (char c : s)
        {
            if (c == 'C')
                carlsen += 2;
            if (c == 'N')
                chef += 2;
            if (c == 'D')
            {
                ++carlsen;
                ++chef;
            }
        }

        if (chef > carlsen)
            cout << 40 * x << endl;
        if (chef == carlsen)
            cout << 55 * x << endl;
        if (chef < carlsen)
            cout << 60 * x << endl;
    }

    return 0;
}