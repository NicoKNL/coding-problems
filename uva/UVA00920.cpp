#include <bits/stdc++.h>

using namespace std;

typedef double T;
struct pt {
    T x, y;

    pt operator-(pt p) {return {x-p.x, y-p.y};}
    pt operator*(T d) {return {x*d, y*d};}
    pt operator/(T d) {return {x/d, y/d};}
};

bool operator<(pt a, pt b){
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

T sq(pt p) {return p.x * p.x + p.y * p.y;}
double abs(pt p) {return sqrt(sq(p));}
T cross(pt v, pt w) {return v.x*w.y - v.y*w.x;}
T orient(pt a, pt b, pt c) {return cross(b-a, c-a);}

bool properInter(pt a, pt b, pt c, pt d, pt & out) {
    double oa = orient(c, d, a),
    ob = orient(c, d, b),
    oc = orient(a, b, c),
    od = orient(a, b, d);

    if (oa*ob < 0 && oc*od < 0) {
        out = (a * ob - b * oa) / (ob - oa);
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int points;
        cin >> points;
        vector<pt> P(points);
        for (int i = 0; i < points; i++) {
            cin >> P[i].x >> P[i].y;
        }

        sort(P.begin(), P.end());

        double dist = 0;
        dist += abs(P[P.size()-1] - P[P.size() - 2]);
        pt peak = P[P.size() - 2];
        pt prepeak = {-1, peak.y};
        pt bottom;
        int i = P.size() - 2;
        while (i >= 0) {
            if (P[i].y > peak.y) {
                properInter(peak, prepeak, P[i], P[i+1], bottom);
                dist += abs(P[i] - bottom);
                peak = P[i];
                prepeak = {-1, peak.y};
            }
            i -= 2;
        }
        cout << setprecision(2) << fixed << dist << endl;
    }
    return 0;
}