#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cities, pilots;
    int tmpA, tmpB;
    while (n--) {
        cin >> cities >> pilots;
        for (int i = 0; i < pilots; i++) {
            cin >> tmpA >> tmpB;
        }
        cout << cities - 1 << endl; // V - 1
    }
    return 0;
}