#include <iostream>

using namespace std;

int main() {
    int n, a, b;
    while (cin >> n) {
        if (n == 0) break;
        bool even = true;
        a = 0;
        b = 0;

        int i = 0;
        while (n > 0) {
            if (n & 1) {
                if (even) {
                    a += (1 << i);
                } else {
                    b += (1 << i);
                }
                even = !even;
            }
            i++;
            n = n >> 1;
        }
        cout << a << " " << b << endl;
    }
    return 0;
}