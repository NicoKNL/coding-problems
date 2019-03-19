#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

int main() {
    int f, r, tmp;
    double spread, max_spread;
    vi front, back;
    vector<double> spreads;

    while (cin >> f) {
        if (f == 0) break;
        cin >> r;

        front.clear(); back.clear();
        for (int i = 0; i < f; i++) { cin >> tmp; front.push_back(tmp); }
        for (int i = 0; i < r; i++) { cin >> tmp; back.push_back(tmp); }

        spreads.clear();
        for (int i = 0; i < f; i++) {
            for (int j = 0; j < r; j++) {
                spreads.push_back((double) back[j] / (double) front[i]);
            }
        }

        sort(spreads.begin(), spreads.end());
        max_spread = 0.0;
        for (int i = 0; i < spreads.size() - 1; i++) {
            spread = spreads[i + 1] / spreads[i];
            max_spread = max(max_spread, spread);
        }

        cout << fixed << setprecision(2) << max_spread << endl;
    }
    return 0;
}