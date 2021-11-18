#include <bits/stdc++.h>

using namespace std;

int main()
{
    int min_x, min_y, max_x, max_y;
    set<pair<int, int>> points;

    for (int i = 0; i < 3; ++i)
    {
        int x, y;
        cin >> x >> y;

        points.insert({x, y});

        if (i == 0)
        {
            min_x = x;
            max_x = x;

            min_y = y;
            max_y = y;
        }
        else
        {
            min_x = min(x, min_x);
            max_x = max(x, max_x);

            min_y = min(y, min_y);
            max_y = max(y, max_y);
        }
    }

    // Test all four options
    if (points.find({min_x, min_y}) == points.end())
    {
        cout << min_x << " " << min_y << endl;
    }
    else if (points.find({min_x, max_y}) == points.end())
    {
        cout << min_x << " " << max_y << endl;
    }
    else if (points.find({max_x, min_y}) == points.end())
    {
        cout << max_x << " " << min_y << endl;
    }
    else
    {
        cout << max_x << " " << max_y << endl;
    }

    return 0;
}