#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        int w = sqrt(s.length());

        vector<vector<char>> V(w, vector<char>(w, '.'));
        for (int r = 0; r < w; ++r)
        {
            for (int c = 0; c < w; ++c)
            {
                V[r][c] = s.at(r * w + c);
            }
        }

        string result;

        for (int c = w - 1; c >= 0; --c)
        {
            for (int r = 0; r < w; ++r)
            {
                result += V[r][c];
            }
        }

        cout << result << endl;
    }

    return 0;
}