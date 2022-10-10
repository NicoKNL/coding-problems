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

T orient(point a, point b, point c)
{
    return cross(b - a, c - a);
}

double ccw(const point &a, const point &b, const point &o)
{
    point x = {a.x - o.x, a.y - o.y};
    point y = {b.x - o.x, b.y - o.y};

    return cross(x, y);
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

pair<pair<point, point>, double> getClosestDistanceToPolyEdge(const vector<point> &V, point shot)
{
    pair<point, point> closest;
    double closest_dist = INT32_MAX;

    for (int i = 0; i < V.size() - 1; ++i)
    {
        double dist = segPoint(V[i], V[i + 1], shot);
        if (dist < closest_dist)
        {
            closest_dist = dist;
            closest = {V[i], V[i + 1]};
        }
    }

    return {closest, closest_dist};
}

bool contains(const vector<point> &V, const point pt)
{
    int winding_nr = 0;

    for (int i = 0; i < V.size() - 1; ++i)
    {
        const point &seg_start = V[i];
        const point &seg_end = V[i + 1];

        if (seg_start == pt)
            return true;
        else if (seg_start.y == pt.y && seg_end.y == pt.y)
        {
            if ((min(seg_start.x, seg_end.x) <= pt.x) && (pt.x <= max(seg_start.x, seg_end.x)))
                return true;
        }
        else
        {
            bool below = seg_start.y < pt.y;

            if (below != (seg_end.y < pt.y))
            {
                double orientation = ccw(pt, seg_end, seg_start);

                if (orientation == 0)
                    return true;

                if (below == (orientation > 0))
                    winding_nr += below ? 1 : -1;
            }
        }
    }

    return (winding_nr != 0);
}

void shoot(const vector<point> &V)
{
    point shot;
    cin >> shot.x >> shot.y;

    auto [edge, dist] = getClosestDistanceToPolyEdge(V, shot);

    if (dist <= 0.001)
        cout << "Winged!" << endl;
    else
    {
        if (contains(V, shot))
            cout << "Hit! " << dist << endl;
        else
            cout << "Miss! " << dist << endl;
    }
}

void solve(int n)
{
    vector<point> V(n + 1);
    for (int i = 0; i < n; ++i)
        cin >> V[i].x >> V[i].y;

    V[n] = V[0];

    int shots;
    cin >> shots;

    for (int i = 0; i < shots; ++i)
        shoot(V);
}

int main()
{
    fixed(cout);
    cout.precision(10);

    int i = 1;
    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        cout << "Case " << i << endl;
        solve(n);
        ++i;
    }
    return 0;
}