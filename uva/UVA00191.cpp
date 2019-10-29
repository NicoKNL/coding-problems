#include <bits/stdc++.h>

using namespace std;
typedef double T;

struct pt {
    T x, y;
    pt operator*(T d) {return {x*d, y*d};}
    pt operator/(T d) {return {x/d, y/d};}
    pt operator-(pt p) {return {x-p.x, y-p.y};}
};

T cross(pt v, pt w) {return v.x*w.y - v.y*w.x;}
T orient(pt a, pt b, pt c) {return cross(b-a, c-a);}
T dot(pt v, pt w) {return v.x*w.x + v.y*w.y;}

bool properInter(pt a, pt b, pt c, pt d, pt & out) {
    double oa = orient(c, d, a),
           ob = orient(c, d, b),
           oc = orient(a, b, c),
           od = orient(a, b, d);
    // Proper intersection exists iff opposite signs
    if (oa*ob < 0 && oc*od < 0) {
        out = (a*ob - b*oa) / (ob-oa);
        return true;
    }
    return false;
}

bool inDisk (pt a, pt b, pt p) {
    return dot(a - p, b - p) <= 0;
}

bool onSegment(pt a, pt b, pt p) {
    return orient(a, b, p) == 0 && inDisk(a, b, p);
}

bool intersects(pt a, pt b, pt c, pt d) {
    pt tmp;
    if (properInter(a, b, c, d, tmp)) return true;
    if (onSegment(c, d, a)) return true;
    if (onSegment(c, d, b)) return true;
    if (onSegment(a, b, c)) return true;
    if (onSegment(a, b, d)) return true;
    return false;
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
    return num_crossings & 1; // inside if crossings == odd
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        T xstart, ystart;
        T xend, yend;
        cin >> xstart >> ystart >> xend >> yend;
        pt start = {xstart, ystart};
        pt end = {xend, yend};

        T xleft, ytop, xright, ybot;
        cin >> xleft >> ytop >> xright >> ybot;
        pt a = {xleft, ytop};
        pt b = {xright, ytop};
        pt c = {xright, ybot};
        pt d = {xleft, ybot};

        vector<pt> poly = {a, b, c, d};

        if (inPolygon(poly, start) && inPolygon(poly, end)) {
            cout << "T" << endl;
        } else if (intersects(start, end, a, b)) {
            cout << "T" << endl;
        } else if (intersects(start, end, b, c)) {
            cout << "T" << endl;
        } else if (intersects(start, end, c, d)) {
            cout << "T" << endl;
        } else if (intersects(start, end, d, a)) {
            cout << "T" << endl;
        } else {
            cout << "F" << endl;
        }
    }

    return 0;
}