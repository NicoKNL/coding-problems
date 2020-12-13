#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
#define loop(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    cin >> n;
    while (n--) {
        int l, m;
        cin >> l >> m;
        l *= 100;
        queue<int> left, right;
        int carlength;
        string side;
        bool ferry_left = true;
        bool ferry_full = false;
        int ferry_available = l;
        int crossings = 0;
        loop(i, m) {
            cin >> carlength >> side;
            if (side == "left") left.push(carlength);
            else right.push(carlength);
        }
        while (!left.empty() || !right.empty()) {
            if (ferry_left) {
                while (!left.empty() && !ferry_full) {
                    if (ferry_available - left.front() >= 0) {
                        ferry_available -= left.front();
                        left.pop();
                    } else {
                        break;
                    }
                }
                if (!left.empty()) {
                    ferry_full = true;
                }
            } else {
                while(!right.empty() && !ferry_full) {
                    if (ferry_available - right.front() >= 0) {
                        ferry_available -= right.front();
                        right.pop();
                    } else {
                        break;
                    }
                }
                if (!right.empty()) {
                    ferry_full = true;
                }
            }

            if (ferry_left && !right.empty()) {
                crossings++;
                ferry_left = false;
                ferry_full = false;
                ferry_available = l;
            } else if (!ferry_left && !left.empty()) {
                crossings++;
                ferry_left = true;
                ferry_full = false;
                ferry_available = l;
            } else if (ferry_full) {
                crossings++;
                ferry_left = !ferry_left;
                ferry_available = l;
                ferry_full = false;
            } else if (ferry_available < l && left.empty() && right.empty()) {
                crossings++;
            }
        }
        cout << crossings << endl;
    }
    return 0;
}