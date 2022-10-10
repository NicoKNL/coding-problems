#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        string road;
        cin >> road;
        int min_dist = INT_MAX;
        bool drugstore = false;
        int cur_dist;
        bool tracking = false;
        for (char c : road) {
            if (tracking) cur_dist++;
            if (c == 'Z') {
                min_dist = 0;
                break;
            } else if (c == 'D') {
                if (!tracking) {
                    tracking = true;
                    drugstore = true;
                    cur_dist = 0;
                } else if (!drugstore) {
                    min_dist = min(min_dist, cur_dist);
                    drugstore = true;
                    cur_dist = 0;
                } else {
                    cur_dist = 0;
                }
            } else if (c == 'R') {
                if (!tracking) {
                    tracking = true;
                    drugstore = false;
                    cur_dist = 0;
                } else if (drugstore) {
                    min_dist = min(min_dist, cur_dist);
                    drugstore = false;
                    cur_dist = 0;
                } else {
                    cur_dist = 0;
                }
            }
        }
        cout << min_dist << endl;
    }
    return 0;
}