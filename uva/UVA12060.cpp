#include <iostream>

using namespace std;

int main() {
    int n, sum;
    string tmp;
    while (cin >> n) {
        if (n == 0) break;
        sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            sum += tmp;
        }
    }
    return 0;
}