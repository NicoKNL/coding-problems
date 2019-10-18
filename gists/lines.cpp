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

// 2D point vector length
T sq(pt p) {return p.x*p.x + p.y*p.y;}
double abs(pt p) {return sqrt(sq(p));}
pt perp(pt p) { return {-p.y, p.x}; }

// -1 if negative, 0 for zero, 1 for positive numbers
template <typename T> int sgn(T x) {
    return (T(0) < x) - (x < T(0));
}

// print points
ostream& operator<<(ostream& os, pt p) {
    return os << "(" << p.x << "," << p.y << ")";
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


/*
 * SEGMENTS
 */



// example
int main() {
    pt a{2, 3};
    pt b{5, 2};
    cout << a+b << " " << a-b << endl;
    return 0;
}