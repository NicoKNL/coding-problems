#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int A, B, C, X, Y;

    while (cin >> A >> B >> C >> X >> Y) {
        if (A == 0 && A == B && B == C && C == X && X == Y) break;

        vector<int> sister = {A, B, C};
        vector<int> prince = {X, Y};

        sort(sister.begin(), sister.end());
        sort(prince.begin(), prince.end());

        bool cards[53] = {false};
        cards[A] = true;
        cards[B] = true;
        cards[C] = true;
        cards[X] = true;
        cards[Y] = true;

        if (prince[0] > sister[2] && prince[1] > sister[2]) {
            bool found = false;
            for (int Z = 1; Z < 53; Z++) {
                if (cards[Z] == false) {
                    cout << Z << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << -1 << endl;
            }
        } else if ((prince[0] < sister[0] && prince[1] < sister[0])
           ||(prince[0] < sister[1] && prince[1] < sister[1])
           ||(prince[0] < sister[0] && prince[1] < sister[1])
           ||(prince[0] < sister[0] && prince[1] < sister[2])
           ||(prince[0] < sister[1] && prince[1] < sister[2])) {
            cout << -1 << endl;
        } else if ((prince[0] < sister[0] && prince[1] < sister[2])
                  ||(prince[0] < sister[1] && prince[1] < sister[2])
                  ||(prince[0] < sister[0] && prince[1] > sister[2])
                  ||(prince[0] < sister[1] && prince[1] > sister[2])) {
            bool found = false;
            for (int Z = sister[2]; Z < 53; Z++) {
                if (cards[Z] == false) {
                    cout << Z << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << -1 << endl;
            }
        } else {
            bool found = false;
            for (int Z = sister[1]; Z < 53; Z++) {
                if (cards[Z] == false) {
                    cout << Z << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << -1 << endl;
            }
        }



    }
    return 0;
}