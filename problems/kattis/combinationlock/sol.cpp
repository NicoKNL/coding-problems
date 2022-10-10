#include <bits/stdc++.h>

using namespace std;

int DEGREES_PER_MARK = 360 / 40;

int turnFullCircle(int times)
{
    return 360 * times;
}

int turnClockwiseToPosition(int &current, int target)
{
    int dist = 0;
    while (current != target)
    {
        --current;

        if (current < 0)
            current += 40;

        dist++;
    };

    return dist * DEGREES_PER_MARK;
}

int turnCounterClockwiseToPosition(int &current, int target)
{
    int dist = 0;

    while (current != target)
    {
        current = (current + 1) % 40;

        dist++;
    };

    return dist * DEGREES_PER_MARK;
}

int main()
{
    int a, b, c, d;
    while (cin >> a >> b >> c >> d)
    {
        if (a == 0 && b == 0 && c == 0 && d == 0)
            break;

        int degrees = 0;
        int current_position = a;

        degrees += turnFullCircle(2);
        degrees += turnClockwiseToPosition(current_position, b);
        degrees += turnFullCircle(1);
        degrees += turnCounterClockwiseToPosition(current_position, c);
        degrees += turnClockwiseToPosition(current_position, d);

        cout << degrees << endl;
    }

    return 0;
}