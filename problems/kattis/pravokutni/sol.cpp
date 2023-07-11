#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define SEGMENTS 360
const double SEGANGLE = 360.0 / SEGMENTS;

bool equals(double a, double b)
{
    return fabs(a - b) < 1e-9;
}

class Point;

class Point
{
public:
    double x, y;
    vector<vector<Point *>> points;

    Point(int n, double _x, double _y)
    {
        x = _x;
        y = _y;

        for (int i = 0; i < SEGMENTS; ++i)
        {
            points.push_back({});
            points[i].reserve(n);
        }
    };

    void addPoint(double angle, Point &p)
    {
        int bucket = static_cast<int>(angle / SEGANGLE);
        points[bucket].push_back(&p);
    }

    vector<Point *> &getBucket(double angle)
    {
        int bucket = static_cast<int>(angle / SEGANGLE);
        return points[bucket];
    }
};

double getAngle(Point &p1, Point &p2)
{
    double angle = atan2(p1.y - p2.y, p1.x - p2.x) * 180.0 / M_PI;
    if (angle < 0)
        angle += 360.0;
    return angle;
}

int main()
{
    int n;
    cin >> n;

    vector<Point> points;

    for (int i = 0; i < n; ++i)
    {
        double x, y;
        cin >> x >> y;
        Point p = Point(n, x, y);
        points.push_back(p);
    }

    for (int u = 0; u < points.size(); ++u)
    {
        Point &p1 = points[u];
        for (int v = u + 1; v < points.size(); ++v)
        {
            Point &p2 = points[v];
            double angle = getAngle(p1, p2);

            p1.addPoint(angle, p2);

            angle -= 180.0;
            if (angle < 0)
                angle += 360.0;

            p2.addPoint(angle, p1);
        }
    }

    int answer = 0;

    for (int u = 0; u < points.size(); ++u)
    {
        Point &p1 = points[u];
        for (int v = u + 1; v < points.size(); ++v)
        {
            Point &p2 = points[v];

            double angle = getAngle(p1, p2);

            double angle1 = angle - 90.0;
            double angle2 = angle + 90.0;

            if (angle1 < 0.0)
                angle1 += 360;

            if (angle2 >= 360.0)
                angle2 -= 360.0;

            for (auto p : p1.getBucket(angle1))
                if (equals(getAngle(p1, *p), angle1))
                    answer += 1;

            for (auto p : p1.getBucket(angle2))
                if (equals(getAngle(p1, *p), angle2))
                    answer += 1;

            for (auto p : p2.getBucket(angle1))
                if (equals(getAngle(p2, *p), angle1))
                    answer += 1;

            for (auto p : p2.getBucket(angle2))
                if (equals(getAngle(p2, *p), angle2))
                    answer += 1;
        }
    }

    cout << answer / 2 << endl;

    return 0;
}