#include <bits/stdc++.h>

using namespace std;

struct Box
{
    int xmin, xmax, ymin, ymax;

    Box()
    {
        cin >> xmin >> xmax >> ymin >> ymax;
    }

    bool in_box(int x, int y)
    {
        return (xmin <= x && x <= xmax && ymin <= y && y <= ymax);
    }
};

int sim(int x, int y, Box &box)
{
    int x_ = 0, y_ = 0;
    int max_y = y;
    for (int i = 0; i < 1000; ++i)
    {
        if (box.in_box(x_, y_))
            return max_y;

        x_ += x;
        y_ += y;

        max_y = max(max_y, y_);

        if (x > 0)
            --x;

        --y;
    }

    return -1;
}

int main()
{
    Box box;

    int best_y = 0;
    for (int x = -500; x < 500; ++x)
        for (int y = -500; y < 500; ++y)
            best_y = max(best_y, sim(x, y, box));

    cout << best_y << endl;
    return 0;
}