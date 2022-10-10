#include <bits/stdc++.h>

using namespace std;

typedef double T;
struct point
{
    T x, y;

    point operator-(const point &p)
    {
        return {x - p.x, y - p.y};
    }
};

bool operator==(const point &a, const point &b)
{
    return a.x == b.x && a.y == b.y;
}

bool operator!=(const point &a, const point &b)
{
    return !(a == b);
}

T square(const point &p)
{
    return p.x * p.x + p.y * p.y;
}

double abs(const point &p)
{
    return sqrt(square(p));
}

T dot(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}

T cross(point a, point b)
{
    return a.x * b.y - a.y * b.x;
}

struct line
{
    point v;
    T c;

    line(point a, point b) : v(b - a), c(cross(v, a)) {}

    T side(point p) { return cross(v, p) - c; }

    double dist(point p) { return abs(side(p)) / abs(v); }

    bool cmpProj(point a, point b) { return dot(v, a) < dot(v, b); }
};

double
segPoint(point a, point b, point p)
{
    if (a != b)
    {
        line l(a, b);

        if (l.cmpProj(a, p) && l.cmpProj(p, b))
        {
            // closest to projection
            return l.dist(p);
        }
    }

    return min(abs(p - a), abs(p - b));
}

int main()
{
    fixed(cout);
    cout.precision(10);

    double x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;

    point post = {x, y};
    point corner1 = {x1, y1};
    point corner2 = {x1, y2};
    point corner3 = {x2, y2};
    point corner4 = {x2, y1};

    double result = DBL_MAX;
    result = min(result, segPoint(corner1, corner2, post));
    result = min(result, segPoint(corner2, corner3, post));
    result = min(result, segPoint(corner3, corner4, post));
    result = min(result, segPoint(corner4, corner1, post));

    cout << result << endl;
}