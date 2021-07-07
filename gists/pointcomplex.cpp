#include <bits/stdc++.h>

using namespace std;

typedef double T;
typedef complex<T> pt;
#define x real()
#define y imag()

pt translate(pt v, pt p) {return p+v;}

// scale from point with factor
pt scale(pt c, double factor, pt p) {
    return c + (p - c) * factor;
}

// General rotation formula
//pt rot(pt p, double a) {
//    return {p.x*cos(a) - p.y*sin(a), p.x*sin(a) + p.y*cos(a)};
//}

// When using complex points
pt rot(pt p, double a) {
    return {p * polar(1.0, a)};
}

// Perpendicular rotation (90 deg.)
pt perp(pt p) { return {-p.y, p.x}; }

T dot(pt v, pt w) {return v.x*w.x + v.y*w.y;}
T dotC(pt v, pt w) {return (conj(v)*w).x;}

bool isPerp(pt v, pt w) {return dot(v,w) == 0;}

double angle(pt v, pt w) {
    double cosTheta = dot(v, w) / abs(v) / abs(w);
    return acos(max(-1.0, min(1.0, cosTheta)));
}

T cross(pt v, pt w) {return v.x*w.y - v.y*w.x;}
T crossC(pt v, pt w) {return (conj(v)*w).y;}

T orient(pt a, pt b, pt c) {return cross(b-a, c-a);}

// Extract linear transform and apply to 3rd point
pt linearTransfo(pt p, pt q, pt r, pt fp, pt fq) {
    return fp + (r - p) * (fq - fp) / (q - p);
}

pt linearTransfo2(pt p, pt q, pt r, pt fp, pt fq) {
    pt pq = q - p, num{cross(pq, fq-fp), dot(pq, fq-fp)};
    return fp + pt{cross(r-p, num), dot(r-p, num)} / sq(pq);
}

// Check if point p is within angle(AB, AC)
bool inAngle(pt a, pt b, pt c, pt p) {
    assert(orient(a, b, c) != 0);
    if (orient(a, b, c) < 0) swap(b, c);
    return orient(a, b, p) >= 0 && orient(a, c, p) <= 0;
}

double orientedAngle(pt a, pt b, pt c) {
    if (orient(a, b, c) >= 0) {
        return angle(b-a, c-a);
    } else {
        return 2*M_PI - angle(b-a, c-a);
    }
}

bool isConvex(vector<pt> p) {
    bool has_pos = false, has_neg = false;
    for (int i = 0, n=p.size(); i < n; i++) {
        int o = orient(p[i], p[(i+1)%n], p[(i+2)%n]);
        if (o > 0) has_pos = true;
        if (o < 0) has_neg = true;
    }
    return !(has_pos && has_neg);
}

// example
int main() {
    pt a{2, 3};
    pt b{5, 2};
    cout << a.x << " " << a.y << endl;
    cout << b << endl;

//    a.x = 1; // does not compile
    a = {1, 2}; // correct
    return 0;
}