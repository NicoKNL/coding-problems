#include <bits/stdc++.h>

using namespace std;

int main()
{
    int width, pieces;
    cin >> width >> pieces;

    int area = 0;

    for (int i = 0; i < pieces; ++i)
    {
        int w, h;
        cin >> w >> h;

        area += w * h;
    }

    cout << area / width << endl;

    return 0;
}