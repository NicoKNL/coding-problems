#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        long sum, diff;
        cin >> sum >> diff;
        if (sum < diff || (sum % 2 == 1 && diff % 2 == 0) || (sum % 2 == 0 && diff % 2 == 1)) {
            cout << "impossible" << endl;
        } else if (diff == 0) {
            cout << sum / 2 << " " << sum / 2 << endl;
        } else if (sum == diff) {
            cout << sum << " " << 0 << endl;
        } else {
            long a = sum / 2;
            long b = sum / 2;

            if (sum % 2 == 1) {
                a++;
            }

            a += diff / 2;
            b -= diff / 2;

            cout << a << " " << b << endl;
        }
    }
    return 0;
}