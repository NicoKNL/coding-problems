#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> offsets = {
        {-1, -1}, {0, -1}, {1, -1},
        {-1, 0},           {1, 0},
        {-1, 1},  {0, 1},  {1, 1}
};

int main() {
    int rows, cols;
    int field = 1;
    while (cin >> rows >> cols) {
        if (rows == 0 && cols == 0) break;

        if (field > 1) cout << endl;

        /* Reading in the input */
        vector<vector<char>> map_in;
        char c;
        for (int y = 0; y < rows; y++) {
            map_in.push_back(vector<char> {});
            for (int x = 0; x < cols; x++) {
                cin >> c;
                map_in.at(y).push_back(c);
            }
        }

        /* Converting the input to the numbered map */
        vector<vector<int>> map_out;
        int count;
        for (int y = 0; y < rows; y++) {
            map_out.push_back(vector<int> {});
            for (int x = 0; x < cols; x++) {
                if (map_in.at(y).at(x) == '*') {
                    map_out.at(y).push_back((int) '*');
                    continue;
                }

                count = 0;
                for (auto offset: offsets) {
                    if (0 <= y + offset[1] && y + offset[1] < rows && 0 <= x + offset[0] && x + offset[0] < cols) {
                        c = map_in.at(y + offset[1]).at(x + offset[0]);
                        if (c == '*') count++;
                    }
                }
                map_out.at(y).push_back(count);
            }
        }

        /* printing out the numbered map */
        cout << "Field #" << field << ":" << endl;
        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                if (map_out.at(y).at(x) == 42) {
                    cout << '*';
                } else {
                    cout << map_out.at(y).at(x);
                }
            }
            cout << endl;
        }
        field++;
    }
    return 0;
}