#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<char>> rotate90(vector<vector<char>> m) {
    char tmpA, tmpB, tmpC, tmpD;

    int l = m.size() % 2 == 1 ? m.size() / 2 + 1 : m.size() / 2;
    int size = m.size();
    int offset = 0;
    for (int row = 0; row < l; row++) {
        for (int col = offset; col < l; col++) {
            tmpA = m[row][col];
            tmpB = m[col][size - row - 1];
            tmpC = m[size - row - 1][size - col - 1];
            tmpD = m[size - col - 1][row];

            m[row][col] = tmpD;
            m[col][size - row - 1] = tmpA;
            m[size - row - 1][size - col - 1] = tmpB;
            m[size - col - 1][row] = tmpC;
        }
        offset++;
    }
    return m;
}

int main() {
    int N, n;
    while (cin >> N >> n) {
        if (N == 0 && n == 0) break;

        vector<vector<char>> big, small;
        string s;
        for (int i = 0; i < N; i++) {
            cin >> s;
            vector<char> row;
            row.reserve(sizeof(char) * N);
            for (char c: s) {
                row.push_back(c);
            }
            big.push_back(row);
        }

        for (int i = 0; i < n; i++) {
            cin >> s;
            vector<char> row;
            row.reserve(sizeof(char) * n);
            for (char c: s) {
                row.push_back(c);
            }
            small.push_back(row);
        }

        int steps = big.size() - small.size() + 1;

        int count;
        bool match;
        for (int i = 0; i < 4; i++) {
            count = 0;
            for (int row = 0; row < steps; row++) {
                for (int col = 0; col < steps; col++) {
                    match = true;
                    for (int srow = 0; srow < small.size(); srow++) {
                        if (!match) break;
                        for (int scol = 0; scol < small.size(); scol++) {
                            if (small[srow][scol] != big[row + srow][col + scol]) {
                                match = false;
                                break;
                            }
                        }
                    }
                    if (match) count++;
                }
            }
            cout << count;
            if (i < 3) cout << " ";
            small = rotate90(small);
        }
        cout << endl;
    }

    return 0;
}