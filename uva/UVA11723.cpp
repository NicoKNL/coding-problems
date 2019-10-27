#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, R;
    int cases = 1;
    while (cin >> R >> N) {
        if (N == 0 && R == 0) break;
        if (R > N * 27) {
            cout << "Case " << cases << ": impossible" << endl;
        } else {
            int count = 0;
            while (R > N * (count + 1)) {
                count++;
            }
            cout << "Case " << cases << ": " << count << endl;
        }
        cases++;
    }
    return 0;
}