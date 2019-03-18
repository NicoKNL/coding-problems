#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int f, r, tmp;
    double ratio, spread;
    vi front, back;
    while (cin >> f) {
        if (f == 0) break;
        cin >> r;

        front.clear(); back.clear();
        for (int i = 0; i < f; i++) { cin >> tmp; front.push_back(tmp); }
        for (int i = 0; i < r; i++) { cin >> tmp; back.push_back(tmp); }

        spread = 0.0;
        for (int i = 0; i < f; i++) {
            for (int j = 0; j < r; j++) {
                ratio = back[j] / front[i];
            }
        }

        // TODO: Store drive ratios in some datastruct, and sort. Then you can find max spread between adjacent ratio gear-pairs.

        cout << fixed << setprecision(2) << spread << endl;
    }
    return 0;
}