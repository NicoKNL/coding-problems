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

T orient(vec2 a, vec2 b, vec2 c)
{
    return cross(b - a, c - a);
}

double ccw(const vec2 &a, const vec2 &b, const vec2 &o)
{
    vec2 x = {a.x - o.x, a.y - o.y};
    vec2 y = {b.x - o.x, b.y - o.y};

    return cross(x, y);
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

pair<pair<vec2, vec2>, double> getClosestDistanceToPolyEdge(const vector<vec2> &V, vec2 shot)
{
    pair<vec2, vec2> closest;
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

bool contains(const vector<vec2> &V, const vec2 pt)
{
    int winding_nr = 0;

    for (int i = 0; i < V.size() - 1; ++i)
    {
        const vec2 &seg_start = V[i];
        const vec2 &seg_end = V[i + 1];

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

void shoot(const vector<vec2> &V)
{
    vec2 shot;
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
    vector<vec2> V(n + 1);
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