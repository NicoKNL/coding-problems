#include<bits/stdc++.h>

using namespace std;

vector<pair<int, int>> circle(int x, int y, int boardsize) {
    vector<pair<int, int>> coords;
    vector<int> offsets = {-1, 0, 1};

    for (int x_offset : offsets) {
        for (int y_offset : offsets) {
            if (x_offset == 0 && y_offset == 0) continue;
            if (x + x_offset < 0 || x + x_offset >= boardsize) continue;
            if (y + y_offset < 0 || y + y_offset >= boardsize) continue;
            coords.push_back(pair<int, int> {x + x_offset, y + y_offset});
        }
    }
    return coords;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int board;
        cin >> board;
        string s;
        vector<vector<char>> b;
        vector<pair<int, int>> q;
        for (int y = 0; y < board; y++) {
            vector<char> row;
            cin >> s;
            for (int x = 0; x < board; x++) {
                row.push_back(s[x]);
                if (s[x] == 'w') {
                    q.push_back(pair<int, int> {x, y});
                }
            }
            b.push_back(row);
        }

        bool changed;
        int counter = 0;
        do {
            changed = false;
            vector<pair<int, int>> adds;
            vector<pair<int, int>> eval_coords;
            for (auto c : q) { // c = coordinate (x, y)
                eval_coords = circle(c.second, c.first, board);
                for (auto coord: eval_coords) {

                    if (b[coord.first][coord.second] == '-') {
                        adds.push_back(pair<int, int>{coord.second, coord.first});
                        b[coord.first][coord.second] = 'w';
                        changed = true;
                    }
                }
            }
            counter += adds.size();
            q.insert(q.end(), adds.begin(), adds.end());
        } while (changed);
        cout << counter << endl;
    }
    return 0;
}