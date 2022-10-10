#include <iostream>

using namespace std;

int main() {
    int banks, debs;
    long int reserves[21];

    while (cin >> banks >> debs) {
        if (banks == 0 && debs == 0) break;
        for (int b = 0; b < banks; b++) {
            cin >> reserves[b+1];
        }

        for (int d = 0; d < debs; d++) {
            int debtor, creditor, value;
            cin >> debtor >> creditor >> value;

            reserves[debtor] -= value;
            reserves[creditor] += value;
        }

        bool bailout = false;
        for (int b = 0; b < banks; b++) {
            if (reserves[b+1] < 0) {
                bailout = true;
            }
        }

        if (bailout) {
            cout << "N" << endl;
        } else {
            cout << "S" << endl;
        }
    }
    return 0;
}