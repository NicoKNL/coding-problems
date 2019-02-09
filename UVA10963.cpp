#include <iostream>
#include <cmath>

using namespace std;

void run() {
    int columns, top, bottom;
    cin >> columns;
    int height;
    bool possible = true;
    for (int c = 0; c < columns; c++) {
        cin >> top >> bottom;

        if (c == 0) {
            height = abs(top - bottom) + 1;
        } else if (height == abs(top - bottom) + 1) {
            continue;
        } else {
            possible = false;
        }
    }

    if (possible) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        run();
        if (n) cout << endl;
    }
    return 0;
}