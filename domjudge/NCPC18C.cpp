#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int pushday;
    cin >> pushday;
    n--;
    int push_count = 0;
    int dirt_sum = 0;
    int cleanups = 0;
    for (int i = 1; i < 366; i++) {
        if (i == pushday) {
            push_count++;
            if (n) {
                cin >> pushday;
                n--;
            }
        }

        if (dirt_sum + push_count >= 20) {
            cleanups++;
            dirt_sum = 0;
            push_count = 0;
        } else {
            dirt_sum += push_count;
        }
    }

    if (dirt_sum > 0) {
        cleanups++;
    }
    cout << cleanups << endl;
    return 0;
}