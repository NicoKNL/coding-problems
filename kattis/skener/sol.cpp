#include <bits/stdc++.h>

using namespace std;

int main()
{
    int nrows, ncols;
    int rz, cz;

    cin >> nrows >> ncols >> rz >> cz;

    for (int r = 0; r < nrows; ++r)
    {
        string s = "";
        for (int c = 0; c < ncols; ++c)
        {
            char tmp;
            cin >> tmp;

            for (int i = 0; i < cz; ++i)
                s += tmp;
        }

        for (int i = 0; i < rz; ++i)
            cout << s << endl;
    }

    return 0;
}