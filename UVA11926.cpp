#include <iostream>
#include <bitset>

using namespace std;

#define SIZE 1000001

int main() {
    int n, m, s, t, repeat;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        bitset<SIZE> calendar;
        bool conflicts = false;
        while (n--) {
            cin >> s >> t;
            if (conflicts) continue;
            for (int i = s; i < t; i++) {
                if (calendar[i]) conflicts = true;
                calendar.set(i);
            }
        }

        while (m--) {
            cin >> s >> t >> repeat;
            if (conflicts) continue;
            while (s < SIZE && !conflicts) {
                for (int i = s; i < t && i < SIZE; i++) {
                    if (calendar[i]) conflicts = true;
                    calendar.set(i);
                }
                s += repeat;
                t += repeat;
            }
        }

        if (conflicts) {
            cout << "CONFLICT" << endl;
        } else {
            cout << "NO CONFLICT" << endl;
        }
    }
    return 0;
}