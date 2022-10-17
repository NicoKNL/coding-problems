#include <iostream>
#include <cmath>

using namespace std;

struct vec2
{
    double x;
    double y;
};

vec2 rot(vec2 p, double a)
{
    return {p.x * cos(a) - p.y * sin(a), p.x * sin(a) + p.y * cos(a)};
}

vec2 normalize(vec2 p)
{
    double length = sqrt(p.x * p.x + p.y * p.y);
    return {p.x / length, p.y / length};
}

void solve()
{
    int n;
    cin >> n;

    vec2 robot = {0, 0};
    vec2 orientation = {0, 1};

    for (int i = 0; i < n; ++i)
    {
        double dir, dist;
        cin >> dir >> dist;
        orientation = rot(orientation, 2 * M_PI * dir / 360.0);
        robot.x += dist * orientation.x;
        robot.y += dist * orientation.y;
    }

    cout << robot.x << " " << robot.y << '\n';
}

int main()
{
    cout.precision(10);

    int n;
    cin >> n;
    while (n--)
    {
        solve();
    }

    return 0;
}