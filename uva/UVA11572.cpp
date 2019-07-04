#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, flakes, f, length, maxlength;
    cin >> n;
    while (n--) {
        map<int, int> m;
        cin >> flakes;
        length = 0;
        maxlength = -1;
        for (int i = 0; i < flakes; i++) {
            cin >> f;
            if (m.find(f) == m.end()) {
                m[f] = i;
                length++;
                maxlength = max(maxlength, length);
            } else {
                length = min(length + 1, i - m[f]);
                maxlength = max(maxlength, length);
                m[f] = i;
            }
        }
        if (maxlength == -1) {
            maxlength = flakes;
        }
        cout << maxlength << endl;
    }
    return 0;
}