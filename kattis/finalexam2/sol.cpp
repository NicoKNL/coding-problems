#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int score = 0;

    char prev;
    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
            cin >> prev;
        else
        {
            char cur;
            cin >> cur;
            if (prev == cur)
                ++score;
            prev = cur;
        }
    }

    cout << score << endl;

    return 0;
}