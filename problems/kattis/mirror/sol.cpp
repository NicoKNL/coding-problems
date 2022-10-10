#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cout << "Test " << i << endl;

        int nrows, ncols;
        cin >> nrows >> ncols;

        vector<string> V(nrows, string(ncols, ' '));
        for (int r = 0; r < nrows; ++r)
            for (int c = 0; c < ncols; ++c)
                cin >> V[r][c];

        reverse(V.begin(), V.end());

        for_each(V.begin(), V.end(),
                 [](string s)
                 {
                     reverse(s.begin(), s.end());
                     cout << s << endl;
                 });
    }

    return 0;
}