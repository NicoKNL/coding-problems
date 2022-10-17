#include <bits/stdc++.h>

using namespace std;

typedef double T;
struct vec2
{
    T x, y;

    vec2 operator-(const vec2 &p)
    {
        return {x - p.x, y - p.y};
    }
};

bool operator==(const vec2 &a, const vec2 &b)
{
    return a.x == b.x && a.y == b.y;
}

bool operator!=(const vec2 &a, const vec2 &b)
{
    return !(a == b);
}

T square(const vec2 &p)
{
    return p.x * p.x + p.y * p.y;
}

double abs(const vec2 &p)
{
    return sqrt(square(p));
}

T dot(vec2 a, vec2 b)
{
    return a.x * b.x + a.y * b.y;
}

T cross(vec2 a, vec2 b)
{
    return a.x * b.y - a.y * b.x;
}

struct line
{
    vec2 v;
    T c;

    line(vec2 a, vec2 b) : v(b - a), c(cross(v, a)) {}

    T side(vec2 p) { return cross(v, p) - c; }

    double dist(vec2 p) { return abs(side(p)) / abs(v); }

    bool cmpProj(vec2 a, vec2 b) { return dot(v, a) < dot(v, b); }
};

double
segPoint(vec2 a, vec2 b, vec2 p)
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

    vec2 post = {x, y};
    vec2 corner1 = {x1, y1};
    vec2 corner2 = {x1, y2};
    vec2 corner3 = {x2, y2};
    vec2 corner4 = {x2, y1};

    double result = DBL_MAX;
    result = min(result, segPoint(corner1, corner2, post));
    result = min(result, segPoint(corner2, corner3, post));
    result = min(result, segPoint(corner3, corner4, post));
    result = min(result, segPoint(corner4, corner1, post));

    cout << result << endl;
}