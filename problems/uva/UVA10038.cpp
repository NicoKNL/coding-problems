#include <iostream>
#include <bitset>
#include <sstream>

using namespace std;

int main() {
    string tmp;
    istringstream ss_in;
    while (getline(cin, tmp)) {
        ss_in.clear();
        ss_in.str(tmp);

        int n, counter_n, next, current;
        bitset<3005> bits;
        bits.reset();
        ss_in >> n;
        counter_n = n;
        ss_in >> current;
        while (--counter_n) {
            ss_in >> next;
            bits.set(abs(current - next));
            current = next;
        }

        bool jolly = true;
        for (int i = 1; i < n; i++) {
            if (bits[i] == 0) {
                jolly = false;
                break;
            }
        }

        if (jolly) {
            cout << "Jolly" << endl;
        } else {
            cout << "Not jolly" << endl;
        }
    }
    return 0;
}