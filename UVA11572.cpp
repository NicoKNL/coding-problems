#include <iostream>
#include <map>

using namespace std;
// TODO: test through uDebug
int main() {
    int n, flakes, f, length, maxlength;
    cin >> n;
    while (n--) {
        map<int, int> m;
        cin >> flakes;
        length = 0;
        for (int i = 0; i < flakes; i++) {
            cin >> f;
            if (m.find(f) == m.end()) {
                length++;
                m[f] = 1;
            } else {
                if (length > maxlength) {
                    maxlength = length;
                }
                length--;
            }
        }
        cout << maxlength << endl;
    }
    return 0;
}