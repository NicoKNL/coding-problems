#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) {
        if (a == -1 && b == -1) {
            break;
        }
        int left = a - b;
        int right = b - a;
        if (left < 0) {
            left += 100;
            left = left % 100;
        }

        if (right < 0) {
            right += 100;
            right = right % 100;
        }
        cout << min(left, right) << endl;
    }
    return 0;
}