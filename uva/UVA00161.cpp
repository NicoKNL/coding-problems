#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void asTime(int i) {
    int hours = i / 3600;
    int minutes = (i % 3600) / 60;
    int seconds = i % 60;
    cout << setfill('0') << setw(2) << hours << ":" << setw(2) << minutes << ":" << setw(2) << seconds << endl;
}

void eval(vector<int> timings) {
    vector<int> tracker;
    bool equals = true;
    bool afterInitial = false;
    for (int i = 0; i < timings.size(); i++) {
        tracker.push_back(0);
    }

    for (int i = 0; i < 18000; i++) {
        for (int t = 0; t < tracker.size(); t++) {
            tracker[t] += 1;
        }

        equals = true;
        for (int t = 0; t < tracker.size(); t++) {
            if (tracker[t] % (2 * timings[t]) >= timings[t] - 5) {
                afterInitial = true;
                equals = false;
            }
            tracker[t] %= (2 * timings[t]);
        }

        if (equals && afterInitial) {
            return asTime(i + 1);
        }
    }
    cout << "Signals fail to synchronise in 5 hours" << endl;
}


int main() {
    int n;
    vector<int> timings;

    int continues = 0;
    while (cin >> n) {
        if (continues == 3) break;
        if (n == 0) {
            if (continues == 0) eval(timings);
            continues++;
            timings.clear();
        } else {
            timings.push_back(n);
            continues = 0;
        }
    }
    return 0;
}