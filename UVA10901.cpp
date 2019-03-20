#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#define INF 1000000000
using namespace std;
typedef pair<int, int> ii;

int main() {
    int c, n, t, m, tmp, l, r, count;
    string side;
    bool ferry_left, traveling;
    vector<ii> cargo;
    cin >> c;
    while (c--) {
        cin >> n >> t >> m;
        queue<ii> L, R;
        cargo.clear();
        for (int i = 0; i < m; i++) {
            cin >> tmp >> side;
            if (side == "left") {
                L.push({i, tmp});
            } else {
                R.push({i, tmp});
            }
        }

        vector<ii> unloading;
        ferry_left = true;
        traveling = false;
        tmp = 0;
        count = 0;
        // Simulate
        int i = -1;
        while (!L.empty() || !R.empty() || traveling) {
            i++;
            if (traveling) {
                tmp++;
                if (tmp == t) {
                    tmp = 0;
                    traveling = false;
                    ferry_left = !ferry_left;
                    // Unloading
                    for (int j = 0; j < cargo.size(); j++) {
                        unloading.push_back({cargo.at(j).first, i});
                    }
                    cargo.clear();
                } else {
                    continue;
                }
            }
            // If left
            if (ferry_left) {
                // And cars left
                if (!L.empty() && L.front().second <= i) {
                    // Load until N if available.
                    while (!L.empty() && L.front().second <= i && tmp < n) {
                        cargo.push_back(L.front());
                        L.pop();
                        tmp++;
                    }
                    traveling = true;
                    tmp = 0;
                } else {
                    // Check if car right, if so => just move the ferry to that location
                    if (!R.empty() && R.front().second <= i) {
                        traveling = true;
                    }
                }
            } else {
                if (!R.empty() && R.front().second <= i) {
                    while (!R.empty() && R.front().second <= i && tmp < n) {
                        cargo.push_back(R.front());
                        R.pop();
                        tmp++;
                    }
                    traveling = true;
                    tmp = 0;
                } else {
                    if (!L.empty() && L.front().second <= i) {
                        traveling = true;
                    }
                }
            }
        }
        sort(unloading.begin(), unloading.end());
        for (ii item: unloading) {
            cout << item.second << endl;
        }
        if (c) cout << endl;
    }
    return 0;
}