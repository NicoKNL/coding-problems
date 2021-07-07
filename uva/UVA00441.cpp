#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int k, tmp;
    bool first = true;
    while (cin >> k) {
        if (k == 0) break;
        if (!first) cout << endl;
        first = false;
        vector<int> v;
        for (int i = 0; i < k; i++) {
            cin >> tmp;
            v.push_back(tmp);
        }

        for (int a = 0; a <= k - 6; a++) {
            for (int b = a + 1; b <= k - 5; b++) {
                for (int c = b + 1; c <= k - 4; c++) {
                    for (int d = c + 1; d <= k - 3; d++) {
                        for (int e = d + 1; e <= k - 2; e++) {
                            for (int f = e + 1; f <= k - 1; f++) {
                                cout << v[a] << " " << v[b] << " " << v[c] << " " << v[d] << " " << v[e] << " " << v[f] << endl;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}