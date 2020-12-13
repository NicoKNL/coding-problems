#include <iostream>

using namespace std;

bool all_digits_unique(int n) {
    int used = 0, prev_used = 0;
    while (n) {
        used ^= 1 << (n % 10);
        if (used < prev_used) return false;
        n /= 10;
        prev_used = used;
    }
    return true;
}

int main() {
    int a = 123456789, b = 123456789;
    cout << all_digits_unique(a) << endl;
    cout << all_digits_unique(b) << endl;
    return 0;
}