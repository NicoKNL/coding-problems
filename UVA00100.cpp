#include <iostream>
#define UPPER 1000001
using namespace std;

int main() {
    long* tracker = new long[UPPER];
    tracker[1] = 1;
    long i, j, low, high;
    while (cin >> i >> j) {
        low = min(i, j);
        high = max(i, j);

        long longest = 0;
        long index, count;
        for (long k = low; k <= high; k++) {
            index = k;
            count = 0;
cycle:
            if (index < UPPER && tracker[index] != 0) {
                longest = max(longest, count + tracker[index]);
                tracker[k] = count + tracker[index];
            } else {
                if (index % 2 == 1) {
                    index = (3 * index + 1) / 2;
                    count += 2;
                } else {
                    index /= 2;
                    count++;
                }
                goto cycle;
            }
        }
        cout << i << " " << j << " " << longest << endl;
    }
    return 0;
}