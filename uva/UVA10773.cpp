#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cases = 1;
    while (n--) {
        double dist, river, boat;
        cin >> dist >> river >> boat;
        if (river >= boat || boat == 0 || river == 0) {
            cout << fixed << setprecision(3) << "Case " << cases << ": " << "can't determine" << endl;
            cases++;
            continue;
        }
        double fastest = dist / boat;
        double other = dist / sqrt((pow(boat, 2) - pow(river, 2)));
        double diff = abs(fastest - other);
        cout << fixed << setprecision(3) << "Case " << cases << ": " << diff << endl;

        cases++;
    }
    return 0;
}