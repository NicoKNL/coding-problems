#include <bits/stdc++.h>

using namespace std;

typedef double T;
struct pt {
    T x, y;

    pt operator-(pt p) {return {x-p.x, y-p.y};}
};

bool operator<(pt a, pt b){
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

T sq(pt p) {return p.x * p.x + p.y * p.y;}
double abs(pt p) {return sqrt(sq(p));}

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
        pt prepeak = {0, peak.y};
        int i = P.size() - 2;
//        while (i > )
        // todo: finish
    }
    return 0;
}