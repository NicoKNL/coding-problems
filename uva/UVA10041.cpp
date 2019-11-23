#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int r;
        cin >> r;
        vi places(r);
        int tmp;
        loop(i, r) cin >> places[i];

        int best_pos = -1;
        long long min_dist = LLONG_MAX;

        for (int i = 1; i < 30000; i++) {
            int dist = 0;
            loop(j, places.size()) {
                dist += abs(i - places[j]);
            }

            if (dist < min_dist) {
                min_dist = dist;
                best_pos = i;
            }
        }
        cout << min_dist << endl;
    }
    return 0;
}