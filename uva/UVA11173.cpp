#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void run() {
    long n, k;
    cin >> n >> k;

    long sum = 0;
    long k_mod;
    for (int i = 1; i <= n; i++) {
        k_mod = k % (1 << i + 1);
        int low = (1 << i - 1);
        int high = (1 << (i + 1) ) - (1 << (i - 1)) - 1;
        if (low <= k_mod && k_mod <= high) sum += (1 << i - 1);
    }
    cout << sum << endl;
}

int main() {
    int n;
    cin >> n;
    while (n--) run();
    return 0;
}
