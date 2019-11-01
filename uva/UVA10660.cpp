#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int areas;
        cin >> areas;
        vector<vector<int>> city (5, vector<int>(5, 0));
        for (int i = 0; i < areas; i++) {
            int r, c, pop;
            cin >> r >> c >> pop;
            city[r][c] = pop;
        }
        
        int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;
        vector<int> best {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX}; // sol, c1, c2, c3, c4, c5
        for (int c1 = 0; c1 < 21; c1++) {
            x1 = c1 / 5; y1 = c1 % 5;
            for (int c2 = c1 + 1; c2 < 22; c2++) {
                x2 = c2 / 5; y2 = c2 % 5;
                for (int c3 = c2 + 1; c3 < 23; c3++) {
                    x3 = c3 / 5; y3 = c3 % 5;
                    for (int c4 = c3 + 1; c4 < 24; c4++) {
                        x4 = c4 / 5; y4 = c4 % 5;
                        for (int c5 = c4 + 1; c5 < 25; c5++) {
                            x5 = c5 / 5; y5 = c5 % 5;
                            int sol = 0, sol1 = 0, sol2 = 0, sol3 = 0, sol4 = 0, sol5 = 0;
                            bool worse = false;
                            for (int r = 0; r < 5; r++) {
                                if (worse) break;
                                for (int c = 0; c < 5; c++) {
                                    if (worse) break;
                                    sol1 = (abs(r-x1) + abs(c-y1)) * city[r][c];
                                    sol2 = (abs(r-x2) + abs(c-y2)) * city[r][c];
                                    sol3 = (abs(r-x3) + abs(c-y3)) * city[r][c];
                                    sol4 = (abs(r-x4) + abs(c-y4)) * city[r][c];
                                    sol5 = (abs(r-x5) + abs(c-y5)) * city[r][c];
                                    sol += min(sol1, min(sol2, min(sol3, min(sol4, sol5))));
                                    if (sol > best[0]) {
                                        worse = true;
                                    }
                                }
                            }
                            if (sol < best[0]) {
                                best = {sol, c1, c2, c3, c4, c5};
                            }
                        }
                    }
                }
            }
        }
        for (int i = 1; i < 6; i++) {
            if (i > 1) cout << " ";
            cout << best[i];
        }
        cout << endl;
    }

    return 0;
}