#include <bits/stdc++.h>

using namespace std;

struct Point
{
    double x, y;

    Point() : x(0), y(0){};

    double cross_product(const Point &b) const
    {
        return (this->x * b.y) - (this->y * b.x);
    }
};

struct Polygon
{
    vector<Point> points;

    template <class InputIterator>
    Polygon(InputIterator first, InputIterator last) : points(first, last){};

    double signedArea()
    {
        double area = 0.0;

        for (size_t i = 0; i < points.size(); ++i)
        {
            area += points[i].cross_product(points[(i + 1) % points.size()]);
        }

        return area / 2.0;
    }
};

int main()
{
    int N;
    cin >> N;

    fixed(cout);
    cout.precision(1);

    while (N)
    {
        vector<Point> points;

        for (int i = 0; i < N; ++i)
        {
            Point p;
            cin >> p.x >> p.y;
            points.push_back(p);
        }

        Polygon poly(points.begin(), points.end());
        double area = poly.signedArea();

        if (area < 0)
        {
            cout << "CW ";
        }
        else
        {
            cout << "CCW ";
        }
        cout << abs(area) << endl;

        cin >> N;
    }
    return 0;
}