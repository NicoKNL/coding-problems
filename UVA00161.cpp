#include <iostream>
#include <vector>

using namespace std;

// TODO: clean up this mess ZzzZzZZZzzz...

int main() {
    int continues = 0;
outside:
    while (continues < 3) {
        vector<int> timings;
        vector<int> tracker;
        int n, smallest = 1000000000;
        cin >> n;
        if (n == 0) {
            continues++;
            if (continues > 1) {
                goto outside;
            }
        } else {
            continues = 0;
        }
        timings.push_back(n);
        tracker.push_back(0);
        if (n < smallest) {
            smallest = n;
        }

        for (int i = 0; i < 18000; i+=smallest) {
            for (int t = 0; t < tracker.size(); t++) {
                tracker[t] += smallest;
                for (int j = 0; j < 5; j++) {
                    if ((tracker[t] + j) % timings[t] > timings[t] - 5) {
                    break;
                }
            }
                cout << tracker[0] << endl;
            }
        }
    }
    return 0;
}