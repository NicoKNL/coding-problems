#include <iostream>
#include <algorithm>
#include <vector>

// TODO: finish

using namespace std;

int main() {
    int A, B, C, X, Y;

    while (cin >> A >> B >> C >> X >> Y) {
        if (A == 0 && A == B && B == C && C == X && X == Y) break;

        vector<int> sister = {A, B, C};
        vector<int> prince = {X, Y};
        sort(sister.begin(), sister.end());
        sort(prince.begin(), prince.end());

        if (prince[0] > sister[0] && prince[1] > sister[1] && sister[2] < 52) {
            cout << sister[2] + 1 << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}