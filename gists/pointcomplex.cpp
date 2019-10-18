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
pt rot(pt p, double a) {
    return {p.x*cos(a) - p.y*sin(a), p.x*sin(a) + p.y*cos(a)};
}

// When using complex points
pt rot(pt p, double a) {
    return {p * polar(1.0, a)};
}

// Perpendicular rotation (90 deg.)
pt perp(pt p) { return {-p.y, p.x}; }

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