#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct point
{
    double x, y;
};

void solve()
{
    double r;
    int n;
    cin >> r >> n;

    vector<point> points;
    for (int i = 0; i < n; ++i)
    {
        point p;
        cin >> p.x >> p.y;
        points.push_back(p);
    }

    points.push_back(points[0]);

    double length = 0.0;
    for (int i = 0; i < points.size() - 1; ++i)
    {
        const point &a = points[i];
        const point &b = points[i + 1];
        length += sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }

    double new_length = length - 2.0 * M_PI * r;
    if (new_length >= 0)
    {
        cout << new_length / length << endl;
    }
    else
    {
        cout << "Not possible" << endl;
    }
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