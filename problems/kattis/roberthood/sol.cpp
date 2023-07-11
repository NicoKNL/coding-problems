#include <vector>
#include <set>
#include <iostream>
#include <cmath>

using namespace std;

struct Pt
{
    /* Point/vector in 2D space */
    double x, y;
    Pt(double x, double y) : x(x), y(y) {}

    friend bool operator<(const Pt &a, const Pt &b)
    {
        return (a.x < b.x) || ((a.x == b.x) && (a.y < b.y));
    }
    friend bool operator==(const Pt &a, const Pt &b)
    {
        return (a.x == b.x) && (a.y == b.y);
    }
    friend Pt operator+(const Pt &a, const Pt &b)
    {
        return Pt(a.x + b.x, a.y + b.y);
    }
    friend Pt operator-(const Pt &a, const Pt &b)
    {
        return Pt(a.x - b.x, a.y - b.y);
    }
    friend Pt operator*(const Pt &a, const double b)
    {
        return Pt(a.x * b, a.y * b);
    }

    friend double operator*(const Pt &a, const Pt &b)
    {
        /* Dot product, result is zero when the two vectors are
         * perpendicular, or one of them is (0,0) */
        return a.x * b.x + a.y * b.y;
    }

    double cross_product(const Pt &b) const
    {
        /* Cross product of two vectors, equal to the (signed)
         * area of the parallelogram spanned by the vectors,
         * positive if b points counter clockwise of this vector
         */
        return (this->x * b.y) - (this->y * b.x);
    }
};

double ccw(const Pt &A, const Pt &B, const Pt &O)
{
    /* Compares the vectors OA and OB, returns positive if OB
       points counter-clockwise from OA, negative if OB points
       clockwise from OA, zero if co-linear. The returned
       value is twice the area of the triangle OAB, positive
       if OAB is counter-clockwise, negative if clockwise.*/
    return (A - O).cross_product(B - O);
}

struct Poly
{
    /* Polygon (not necessarily convex) */
    vector<Pt> points; /* Vertices of the polygon in
                             counter-clockwise order */
    template <class InputIterator>
    Poly(InputIterator first, InputIterator last)
        : points(first, last){};

    static Poly convex_hull(const vector<Pt> &points)
    {
        vector<Pt> lh, uh, hull;
        const set<Pt> S(points.begin(), points.end());

        if (S.size() <= 1)
            return Poly(S.begin(), S.end());

        /* Build lower hull (lh) and upper hull (uh) */
        for (const auto &p : S)
        {
            while ((lh.size() >= 2) &&
                   (ccw(lh.back(), p, lh.end()[-2]) <= 0))
                lh.pop_back();
            lh.push_back(p);
        }
        for (auto p = S.rbegin(); p != S.rend();
             p++)
        {
            while ((uh.size() >= 2) &&
                   (ccw(uh.back(), *p, uh.end()[-2]) <= 0))
                uh.pop_back();
            uh.push_back(*p);
        }

        /* Concatenation of the lower and upper hulls gives the
         * convex hull */
        copy(lh.begin(), lh.end() - 1, back_inserter(hull));
        copy(uh.begin(), uh.end() - 1, back_inserter(hull));
        return Poly(hull.begin(), hull.end());
    }
};

double dist(Pt p, Pt q)
{
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

double absArea(Pt p, Pt q, Pt r)
{
    return abs((p.x * q.y + q.x * r.y + r.x * p.y) -
               (p.y * q.x + q.y * r.x + r.y * p.x));
}

// A function to calculate the width of the smallest bounding rectangle
double rotatingCaliper(vector<Pt> &hull)
{
    int n = hull.size();

    // If the convex hull has only one point, the width is 0
    if (n == 1)
        return 0;

    // If the convex hull has two points, the width
    // is the distance between the two points
    if (n == 2)
        return sqrt(dist(hull[0], hull[1]));

    int k = 1;

    while (absArea(hull[n - 1], hull[0], hull[(k + 1) % n]) >
           absArea(hull[n - 1], hull[0], hull[k]))
    {
        k++;
    }

    double res = 0;

    for (int i = 0, j = k; i <= k; i++)
    {

        while (absArea(hull[i], hull[(i + 1) % n], hull[(j + 1) % n]) >
               absArea(hull[i], hull[(i + 1) % n], hull[j]))
        {
            res = max(res, sqrt(dist(hull[i], hull[(j + 1) % n])));
            j = (j + 1) % n;
        }

        res = max(res, sqrt(dist(hull[i], hull[j])));
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(12);
    fixed(cout);

    int n;
    cin >> n;

    vector<Pt> points;

    while (n--)
    {
        double x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    vector<Pt> hull = Poly::convex_hull(points).points;
    cout << rotatingCaliper(hull) << endl;
}
