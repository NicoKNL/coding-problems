#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define INF 1000000000

int main() {
    int m, tmp, dist, min_dist;
    string s_tmp;
    vvi grid;
    while (cin >> m) {
        grid.clear();
        // Input
        for (int r = 0; r < m; r++) {
            vi row;
            cin >> s_tmp;
            for (int c = 0; c < m; c++) {
                row.push_back(s_tmp.at(c) - '0');
            }
            grid.push_back(row);
        }

        // Logic
        dist = 0;
        for (int ra = 0; ra < m; ra++) {
            for (int ca = 0; ca < m; ca++) {
                if (grid[ra][ca] != 1) continue;
                min_dist = INF;
                for (int rb = 0; rb < m; rb++) {
                    for (int cb = 0; cb < m; cb++) {
                        if (grid[rb][cb] != 3) continue;
                        min_dist = min(min_dist, abs(ra - rb) + abs(ca - cb));
                    }
                }
                dist = max(dist, min_dist);
            }
        }
        cout << dist << endl;
    }
    return 0;
}