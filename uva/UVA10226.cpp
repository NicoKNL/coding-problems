#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

int main() {
    int n, count;
    string s;
    cin >> n;
    cin.ignore();
    cin.ignore();

    while (n--) {
        map<string, int> omap;
        count = 0;
        while(getline(cin, s)) {
            if (s.empty()) break;
            if (omap.find(s) == omap.end()) {
                omap[s] = 1;
            } else {
                omap[s] += 1;
            }
            count++;
        }

        double result;
        for (auto it: omap) {
            cout << it.first << " " << fixed << setprecision(4) << (double) it.second * 100.0 / (double) count << endl;
        }

        if (n) cout << endl;
    }
}