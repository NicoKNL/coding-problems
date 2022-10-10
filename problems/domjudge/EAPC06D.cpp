#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string target, a, b;
    while (n--) {
        cin >> target >> a >> b;
        int t = 0;
        for (int i = 0; i < a.length() && t < target.length(); i++) {
            if ((target[t] == a[i]) || (target[t] == b[i]) || (a[i] == '*') || (b[i] == '*')) {
                t++;
            }
        }
        if (t == target.length()) {
            cout << "win" << endl;
        } else {
            cout << "lose" << endl;
        }

    }
    return 0;
}