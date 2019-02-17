#include <iostream>
#include <vector>

using namespace std;

int main() {
    int s, b;
    while (cin >> s >> b) {
        if (s == 0 && b == 0) break;

        vector<vector<int>> soldiers;
        int left, right;
        for (int i = 0; i <= s + 1; i++) {
            left = i - 1 < 1 ? 0 : i - 1;
            right = i + 1 > s ? 0 : i + 1;
            soldiers.push_back(vector<int> {left, right});
        }

        vector<int> L, R, new_neighbours;
        while (b--) {
            cin >> left >> right;
            L = soldiers[left];
            R = soldiers[right];

            soldiers[L[0]][1] = R[1];
            soldiers[R[1]][0] = L[0];
            new_neighbours = vector<int> {L[0], R[1]};

            for (int i = 0; i < 2; i++) {
                if (new_neighbours[i] == 0) {
                    cout << '*';
                } else {
                    cout << new_neighbours[i];
                }
                if (i == 0) {
                    cout << " ";
                } else {
                    cout << endl;
                }
            }
        }
        if (b) cout << "-" << endl;
    }
}