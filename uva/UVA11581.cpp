#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string row;
        vector<vector<int>> grid;
        for (int i = 0; i < 3; i++) {
            cin >> row;
            vector<int> gridrow;
            for (char c: row) {
                gridrow.push_back(c - '0');
            }
            grid.emplace_back(gridrow);
        }

        vector<vector<int>> tmp1, tmp2;
        tmp1 = grid;
        tmp2 = grid;
        for (int i = 0; i < 100; i++) {
            for (int r = 0; r < 3; r++) {
                for (int c = 0; c < 3; c++) {
                    int sum = 0;
                    if (r > 0) sum += tmp1[r-1][c];
                    if (c > 0) sum += tmp1[r][c-1];
                    if (r < 2) sum += tmp1[r+1][c];
                    if (c < 2) sum += tmp1[r][c+1];
                    tmp2[r][c] = sum % 2;
                }
            }
            if (tmp1 == tmp2) {
                cout << i - 1 << endl;
                break;
            }
            tmp1 = tmp2;
        }
    }
    return 0;
}