#include <iostream>
#include <vector>

using namespace std;

struct Pt
{
    /* Point/vector in 2D space */
    double x, y;
    Pt() {}
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

    bool contains(const Pt &p) const
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
                return true; /* On boundary as vertex*/
            else if ((seg_start.y == p.y) &&
                     (seg_end.y == p.y))
            {
                /* Check if the point is on the boundary of
                 * the horizontal segment */
                if ((min(seg_start.x, seg_end.x) <= p.x) &&
                    (p.x <= max(seg_start.x, seg_end.x)))
                    return true;
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
                        return true; // On boundary of a segment
                    if (below == (orientation > 0))
                        winding_nr += below ? 1 : -1;
                }
            }
        }
        return (winding_nr != 0);
    }
};

int main()
{
    fixed(cout);
    cout.precision(1);

    // Construct polygon
    vector<Pt> points(3);
    cin >> points[0].x >> points[0].y;
    cin >> points[1].x >> points[1].y;
    cin >> points[2].x >> points[2].y;

    // Answer area
    Poly poly(points.begin(), points.end());
    cout << poly.area() << endl;

    // Perform queries
    int n;
    cin >> n;

    int inside = 0;
    for (int i = 0; i < n; ++i)
    {
        Pt p;
        cin >> p.x >> p.y;

        if (poly.contains(p))
            ++inside;
    }

    cout << inside << endl;
}
