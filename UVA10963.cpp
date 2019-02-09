#include <iostream>
#include <cmath>

using namespace std;

void run() {
    int columns, top, bottom;
    cin >> columns;
    int height;
    for (int c = 0; c < columns; c++) {
        cin >> top >> bottom;

        if (c == 0) {
            height = top - bottom + 1;
        } else if (height == top - bottom + 1) {
            continue;
        } else {
            cout << "no" << endl;
        }
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) run();
    return 0;
}