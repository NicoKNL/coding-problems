#include <iostream>
#include <vector>
#include <set>
#include <sstream>
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
        /* Returns the convex hull of a list of points.
         * Uses Andrew's monotone chain algorithm.
         * $O(|apoints| \log |apoints|)$*/
        vector<Pt> lh, uh, hull;

        // Sort points lexicographically, and remove duplicates
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

double len(Pt &p)
{
    return sqrt(p.x * p.x + p.y * p.y);
}

// example
int main()
{
    fixed(cout);
    cout.precision(8);

    string line;
    while (getline(cin, line))
    {
        stringstream ss(line);
        vector<Pt> points;
        double x, y;
        while (ss >> x >> y)
        {
            points.push_back({x, y});
            cout << "(" << x << ", " << y << ")" << endl;
        }

        cout << "~~~~~~" << endl;

        if (points.size() == 1)
        {
            cout << 100.0 << endl;
            continue;
        }

        Poly hull = Poly::convex_hull(points);
        for (int i = 0; i < hull.points.size(); ++i)
        {
            cout << "(" << hull.points[i].x << ", " << hull.points[i].y << ")" << endl;
        }
        cout << "----------" << endl;
        cout << "points: " << hull.points.size() << endl;
        Pt dist_vec = *hull.points.begin() - *hull.points.end();
        double border = len(dist_vec);
        cout << "D: " << len(dist_vec) << endl;

        for (int i = 0; i < hull.points.size() - 1; ++i)
        {
            Pt dist = hull.points[i] - hull.points[i + 1];
            cout << "(" << hull.points[i].x << ", " << hull.points[i].y << ")" << endl;
            cout << "(" << hull.points[i + 1].x << ", " << hull.points[i + 1].y << ")" << endl;
            cout << "???(" << dist.x << ", " << dist.y << ")" << endl;

            cout << "D: " << len(dist) << endl;
            cout << endl
                 << endl;
            border += len(dist);
        }

        cout << "border: " << border << endl;
        double score = (100.0 * (double)points.size()) / (1.0 + border);
        cout << score << endl;
        cout << endl
             << endl
             << endl;
    }

    return 0;
}