#include <iostream>

using namespace std;

bool all_digits_used(int n) {
    int used = 0;
    while (n) {
        used |= 1 << (n % 10);
        n /= 10;
    }
    return used == (1 << 10) - 1;
}

int main() {
    int a = 123456789, b = 1023456789;
    cout << all_digits_used(a) << endl;
    cout << all_digits_used(b) << endl;
    return 0;
}