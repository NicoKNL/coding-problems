#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    cout << "Lumberjacks:" << endl;
    while (n--) {
        int direction = 0; // -1 down, 1 up, 0 at start
        bool direction_found = false;
        bool ordered = true;
        int previous, current;
        for (int i = 0; i < 10; i++) {
            if (i == 0) {
                cin >> previous;
            } else if (!direction_found) {
                cin >> current;
                if (current > previous) {
                    direction = 1;
                    direction_found = true;
                } else if (current < previous) {
                    direction = -1;
                    direction_found = true;
                } else {
                    continue;
                }
                previous = current;
            } else {
                cin >> current;
                if ((direction == 1 && current < previous) || (direction == -1 && current > previous)) {
                    ordered = false;
                }
                previous = current;
            }
        }

        if (ordered) {
            cout << "Ordered" << endl;
        } else {
            cout << "Unordered" << endl;
        }
    }
    return 0;
}