#include <vector>
#include <set>
#include <iostream>

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

    double area()
    /* Returns the area of the polygon $O(|points|)$ */
    {
        double area = 0.0;
        for (size_t i = 0; i < points.size(); i++)
        {
            area += points[i].cross_product(
                points[(i + 1) % points.size()]);
        }
        return abs(area) / 2.0;
    }

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

    int contains(const Pt &p) const
    {
        /* Returns whether a point is inside (or on the border
         * of) the polygon. Uses the winding number method
         * (works for non-convex polygons) $O(|points|)$. */
        long long winding_nr = 0;

        for (size_t i = 0; i < points.size(); i++)
        {
            const Pt &seg_start = points[i];
            const Pt &seg_end =
                points[(i + 1) % points.size()];

            if (seg_start == p)
                return 0; /* On boundary as vertex*/
            else if ((seg_start.y == p.y) &&
                     (seg_end.y == p.y))
            {
                /* Check if the point is on the boundary of
                 * the horizontal segment */
                if ((min(seg_start.x, seg_end.x) <= p.x) &&
                    (p.x <= max(seg_start.x, seg_end.x)))
                    return 0;
            }
            else
            {
                /* Update the winding number */
                bool below = seg_start.y < p.y;
                if (below != (seg_end.y < p.y))
                {
                    double orientation =
                        ccw(p, seg_end, seg_start);
                    if (orientation == 0)
                        return 0; // On boundary of a segment
                    if (below == (orientation > 0))
                        winding_nr += below ? 1 : -1;
                }
            }
        }

        if (winding_nr != 0)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    int n;

    while (cin >> n)
    {
        if (n == 0)
            break;

        vector<Pt> points;

        while (n--)
        {
            double x, y;
            cin >> x >> y;
            points.push_back({x, y});
        }

        Poly poly(points.begin(), points.end());

        int m;
        cin >> m;

        while (m--)
        {
            Pt pt(0, 0);
            cin >> pt.x >> pt.y;

            int pos = poly.contains(pt);
            if (pos == 1)
            {
                cout << "in\n";
            }
            else if (pos == 0)
            {
                cout << "on\n";
            }
            else
            {
                cout << "out\n";
            }
        }
    }
}