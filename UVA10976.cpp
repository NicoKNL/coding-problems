#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int k, x;
    double kfrac, xfrac, yfrac, tmp;
    vector<pair<int, int>> pairs;
    while (cin >> k) {
        pairs.clear();
        kfrac = 1.0 / k;
        x = k;
        while (x++) {
            xfrac = 1.0 / x;
            yfrac = kfrac - xfrac;
            tmp = round(1.0 / yfrac);
            if (x * (tmp - k) == (k * tmp)) pairs.push_back({round(1 / yfrac), x});
            if (yfrac < 0) continue;
            if (xfrac <= yfrac) break;
        }

        cout << pairs.size() << endl;
        for (auto pair: pairs) {
            cout << "1/" << k << " = 1/" << pair.first << " + 1/" << pair.second << endl;
        }
    }
    return 0;
}