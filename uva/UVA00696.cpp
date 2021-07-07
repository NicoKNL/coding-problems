#include <iostream>

using namespace std;

int main() {
    int rows, cols, tmp;
    while (cin >> rows >> cols) {
        if (rows == 0 && cols == 0) break;
        if (min(rows, cols) == 1) {
            cout << max(rows, cols);
        } else if (min(rows, cols) == 2) {
            tmp = 0;
            for (int i = 0; i < max(rows, cols); i++) {
                if (i % 4 == 0 || i % 4 == 1) tmp += 2;
            }
            cout << tmp;
        } else {
            cout << ((rows + 1) / 2) * ((cols + 1) / 2) + (rows / 2) * (cols / 2);
        }
        cout << " knights may be placed on a " << rows << " row " << cols << " column board." << endl;
    }
    return 0;
}