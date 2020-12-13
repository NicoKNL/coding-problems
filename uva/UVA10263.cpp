#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef double T;

struct pt {
    T x, y;
    pt operator-(pt p) {return {x-p.x, y-p.y};}
    pt operator*(T d) {return {d * x, d * y};}
    pt operator+(T d) {return {x, y+d};}
    pt operator/(T d) {return {x/d, y/d};}
};

bool operator==(pt a, pt b) {return a.x == b.x && a.y == b.y;}
bool operator!=(pt a, pt b) {return !(a == b);}

T sq(pt p) {return p.x * p.x + p.y * p.y;}
double abs(pt p) {return sqrt(sq(p));}

T cross(pt v, pt w) {return v.x*w.y - v.y*w.x;}
T dot(pt v, pt w) {return v.x*w.x + v.y * w.y;}

pt perp(pt p) {return {-p.y, p.x};}

struct line {
    pt v; T c;

    line(pt p, pt q) : v(q-p), c(cross(v, p)) {}
    T side(pt p) {return cross(v, p) - c;}
    double dist(pt p) {return abs(side(p)) / abs(v);}
    bool cmpProj(pt p, pt q) {return dot(v, p) < dot(v, q);}

    pt proj(pt p) {return p - perp(v) * side(p) / sq(v);}
};

pair<double, pt> segPoint(pt a, pt b, pt p) {
    if (a != b) {
        line l(a, b);
        if (l.cmpProj(a, p) && l.cmpProj(p, b)) {
            // closest to projection!
            return {l.dist(p), l.proj(p)};
        }
    }

    if (abs(p-a) < abs(p-b)) {
        return {abs(p-a), a};
    } else {
        return {abs(p-b), b};
    }
}

int main() {
    double x, y;
    while (cin >> x >> y) {
        pt M = {x, y};
        int segments;
        cin >> segments;

        vector<pt> line;
        for (int i = 0; i <= segments; i++) {
            cin >> x >> y;
            line.push_back({x, y});
        }

        double min_dist = DBL_MAX;
        pt closest = line[0];
        pair<double, pt> dist;
        for (int i = 0; i < line.size() - 1; i++) {
            pt a = line[i];
            pt b = line[i + 1];
            dist = segPoint(a, b, M);
            if (dist.first < min_dist) {
                min_dist = dist.first;
                closest = dist.second;
            }
        }
        cout << fixed << setprecision(4) << closest.x << endl << closest.y << endl;
    }
    return 0;
}

/*
6
-3
3
0
1
5
5
9
-5
15
3
0
0
1
1
0
2
0

878.75991
283.95685
0
7480.97052
9717.37625
 */