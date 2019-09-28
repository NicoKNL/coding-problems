#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    while (n--) {
        map<char, int> m;
        cin >> s;
        char next = 'x';
        bool fake = false;

        for (char c: s) {
            if (next != 'x') {
                if (next == c) {
                    next = 'x';
                    continue;
                } else {
                    fake = true;
                    break;
                }
            }

            if (m.find(c) != m.end()) {
                m[c]++;
                if (m[c] % 3 == 0) {
                    next = c;
                }
            } else {
                m[c] = 1;
            }
        }
        if (next != 'x') {
            fake = true;
        }
        if (fake) {
            cout << "FAKE" << endl;
        } else {
            cout << "OK" << endl;
        }
    }
    return 0;
}