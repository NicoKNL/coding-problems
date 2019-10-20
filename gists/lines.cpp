#include <bits/stdc++.h>

using namespace std;

typedef double T;
struct pt {
    T x, y;
    pt operator+(pt p) {return {x+p.x, y+p.y};}
    pt operator-(pt p) {return {x-p.x, y-p.y};}
    pt operator*(T d) {return {x*d, y*d};}
    pt operator/(T d) {return {x/d, y/d};}
    // ^ only for floating-point ^
};
T cross(pt v, pt w) {return v.x*w.y - v.y*w.x;}
T dot(pt v, pt w) {return v.x*w.x + v.y*w.y;}
T sq(pt p) {return p.x*p.x + p.y*p.y;}

double abs(pt p) {return sqrt(sq(p));}

// Equality testing
bool operator==(pt a, pt b) {return a.x == b.x && a.y == b.y;}
bool operator!=(pt a, pt b) {return !(a == b);}
bool operator<(pt a, pt b) {return a.x < b.x || (a.x == b.x && a.y < b.y);}

// 2D point vector length
//T sq(pt p) {return p.x*p.x + p.y*p.y;}
//double abs(pt p) {return sqrt(sq(p));}
pt perp(pt p) { return {-p.y, p.x}; }

// -1 if negative, 0 for zero, 1 for positive numbers
template <typename T> int sgn(T x) {
    return (T(0) < x) - (x < T(0));
}

// print points
ostream& operator<<(ostream& os, pt p) {
    return os << "(" << p.x << "," << p.y << ")";
}

bool smaller(pt a, pt b) {
}

struct line {
    pt v; T c;

    // From direction vector v and offset c
    line(pt v, T c) : v(v), c(c) {}
    // From equation ax + by = c
    line(T a, T b, T c) : v({b, -a}), c(c) {}
    // From points P and Q
    line(pt p, pt q) : v(q-p), c(cross(v, p)) {}

    // ---- these work with T = int ----
    T side(pt p) {return cross(v, p) - c;}
    double dist(pt p) {return abs(side(p)) / abs(v);}
    double sqDist(pt p) {return side(p)*side(p) / (double) sq(v);}

    // sort on line
    bool cmpProj(pt p, pt q) {return dot(v, p) < dot(v, q);}
    line translate(pt t) {return {v, c + cross(v, t)};}
    line perpThrough(pt p) { return {p, p + perp(v)};}
    // ---- these require T = double ----
    line shiftLeft(double dist) {return {v, c + dist * abs(v)};}
    // orthogonal projection
    pt proj(pt p) {return p - perp(v) * side(p) / sq(v);}
    // reflection
    pt refl(pt p) {return p - perp(v) * 2 * side(p) / sq(v);}
};

bool inter(line l1, line l2, pt & out) {
    T d = cross(l1.v, l2.v);
    if (d == 0) return false;
    out = (l2.v*l1.c - l1.v*l2.c) / d; // requires floating point coords
    return true;
}

line bisector(line l1, line l2, bool interior) {
    assert(cross(l1.v, l2.v) != 0); // l1 and l2 can't be parallel!
    double sign = interior ? 1 : -1;
    return {l2.v / abs(l2.v) + l1.v / abs(l1.v) * sign,
            l2.c / abs(l2.v) + l1.c / abs(l1.v) * sign};
}
T orient(pt a, pt b, pt c) {return cross(b-a, c-a);}


/*
 * SEGMENTS
 */
bool inDisk(pt a, pt b, pt p) {
    return dot(a-p, b-p) <= 0;
}

bool onSegment(pt a, pt b, pt p) {
    return orient(a, b, p) == 0 && inDisk(a, b, p);
}

bool properInter(pt a, pt b, pt c, pt d, pt & out) {
    double oa = orient(c, d, a),
           ob = orient(c, d, b),
           oc = orient(a, b, c),
           od = orient(a, b, d);
    // Proper intersection exists iff opposite signs
    if (oa * ob < 0 && oc * od < 0) {
        out = (a * ob - b * oa) / (ob - oa);
        return true;
    }
    return false;
}

struct cmpX {
    bool operator()(pt a, pt b) {
        return make_pair(a.x, a.y) < make_pair(b.x, b.y);
    }
};

set<pt, cmpX> inters(pt a, pt b, pt c, pt d) {
    pt out;
    if (properInter(a, b, c, d, out)) return {out};
    set<pt, cmpX> s;
    if (onSegment(c, d, a)) s.insert(a);
    if (onSegment(c, d, b)) s.insert(b);
    if (onSegment(a, b, c)) s.insert(c);
    if (onSegment(a, b, d)) s.insert(d);
    return s;
}

double segPoint(pt a, pt b, pt p) {
    if (a != b) {
        line l(a, b);
        if (l.cmpProj(a, p) && l.cmpProj(p,b)) {
            // closest to projection!
            return l.dist(p);
        }
    }
    // otherwise dist to A or B
    return min(abs(p-a), abs(p-b));
}

double segSeg(pt a, pt b, pt c, pt d) {
    pt tmp;
    if (properInter(a, b, c, d, tmp)) {
        return 0;
    }
    return min({segPoint(a, b, d), segPoint(a, b, d),
                segPoint(c, d, a), segPoint(c, d, b)});
}

double areaTriangle(pt a, pt b, pt c) {
    return abs(cross(b-a, c-a)) / 2.0;
}

double areaPolygon(vector<pt> p) {
    double area = 0.0;
    for (int i = 0, n = p.size(); i < n; i++) {
        area += cross(p[i], p[(i+1)%n]);
    }
    return abs(area) / 2.0;
}

pt centroidPolygon(vector<pt> p) {
    pt c {0, 0};
    double scale = 6.0 * areaPolygon(p);
    for (int i = 0, n = p.size(); i < n; i++) {
        c = c + (p[i] + p[(i+1)%n]) * (p[i].x * p[(i+1)%n].y - p[(i+1)%n].x * p[i].y);
    }
    return c / scale;
}

bool above(pt a, pt p) {
    return p.y >= a.y;
}

bool crossesRay(pt a, pt p, pt q) {
    return (above(a, q) - above(a, p)) * orient(a, p, q) > 0;
}

bool inPolygon(vector<pt> p, pt a, bool strict = true) {
    int num_crossings = 0;
    for (int i = 0, n = p.size(); i < n; i++) {
        if (onSegment(p[i], p[(i+1)%n], a)) {
            return !strict;
        }
        num_crossings += crossesRay(a, p[i], p[(i+1)%n]);
    }
    return num_crossings & 1; // inside if crossings = odd
}

pt circumCenter(pt a, pt b, pt c) {
    b = b-a, c = c-a; // Consider relative to A
    assert(cross(b, c) != 0); // no circumcircle if A, B, C aligned
    return a + perp(b * sq(c) - c * sq(b)) / cross(b, c) / 2;
}

int circleLine(pt o, double r, line l, pair<pt, pt> & out) {
    double h2 = r * r - l.sqDist(o);
    if (h2 >= 0) { // the line touches the circle
        pt p = l.proj(o); // point P
        pt h = l.v * sqrt(h2) / abs(l.v); // vector parallel to l, of length h
        out = {p - h, p + h}; // out.first == out.second if only 1 intersect
    }
    return 1 + sgn(h2);
}

int circleCircle(pt o1, double r1, pt o2, double r2, pair<pt, pt> & out) {
    pt d = o2-o1;
    double d2 = sq(d);
    if (d2 == 0) {
        assert(r1 != r2); // concentric circles
        return 0;
    }
    double pd = (d2 + r1 * r1 - r2 * r2) / 2;
    double h2 = r1 * r1 - pd * pd / d2;
    if (h2 >= 0) {
        pt p = o1 + d * pd / d2;
        pt h = perp(d) * sqrt(h2 / d2);
        out = {p - h, p + h};
    }
    return 1 + sgn(h2);
}

int tangents(pt o1, double r1, pt o2, double r2, bool inner, vector<pair<pt, pt>> & out) {
    if (inner) {
        r2 = -r2;
    }
    pt d = o2 - o1;
    double dr = r1 - r2, d2 = sq(d), h2 = d2 - dr * dr;
    if (d2 == 0 || h2 < 0) {
        assert(h2 != 0);
        return 0;
    }
    for (double sign : {-1, 1}) {
        pt v = (d * dr + perp(d) * sqrt(h2) * sign) / d2;
        out.push_back({o1 + v * r1, o2 + v * r2});
    }
    return 1 + (h2 > 0);
}

vector<pt> convexHull(vector<pt> p) {
    int n = p.size();
    int k = 0;
    vector<pt> hull;
    sort(p.begin(), p.end()); // lexicographically sort

    // build lower hull
    for (int i = 0; i < n; i++) {
        while (k >= 2 && cross(hull[k - 2] - p[i], hull[k - 1] - p[i]) <= 0) {
            k--;
        }
        hull.insert(hull.begin() + k, p[i]);
        k++;
    }
    // build upper hull
    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && cross(hull[k-2] - p[i], hull[k-1] - p[i]) <= 0) {
            k--;
        }
        hull.insert(hull.begin() + k, p[i]);
        k++;
    }
    while (hull.size() > k) {
        hull.pop_back();
    }
    return hull;
}

// example
int main() {
    pt p1{1, 1};
    pt p2{2, 2};
    pt p3{3, 3};
    pt p4{4, 4};
    pt p5{2, 3};
    pt p6{1, 5};
    pt p7{5, 1};

    vector<pt> p = {p1, p2, p3, p4, p5, p6, p7};
    vector<pt> hull = convexHull(p);
    cout << "hi" << endl;
//    cout << a+b << " " << a-b << endl;
    return 0;
}