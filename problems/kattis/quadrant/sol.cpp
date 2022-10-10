#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> quadrants = {
    {{1, 1}, 1},
    {{-1, 1}, 2},
    {{-1, -1}, 3},
    {{1, -1}, 4}};

int main()
{
    int x, y;
    cin >> x >> y;

    if (x > 0)
    {
        x = 1;
    }
    else
    {
        x = -1;
    }

    if (y > 0)
    {
        y = 1;
    }
    else
    {
        y = -1;
    }

    cout << quadrants[{x, y}] << endl;

    return 0;
}