#include <iostream>

using namespace std;
int n, rows, cols, count;
char piece;

int main() {
    cin >> n;
    while (n--) {
        cin >> piece >> rows >> cols;
        if (piece == 'r') cout << min(rows, cols) << endl;
        if (piece == 'K') {
            if (rows % 2 == 1) rows++;
            if (cols % 2 == 1) cols++;
            cout << rows / 2 * cols / 2 << endl;
        }
        if (piece == 'k') {
            cout << ((rows + 1) / 2) * ((cols + 1) / 2) + (rows / 2) * (cols / 2) << endl;
        }
        if (piece == 'Q') {
            cout << min(rows, cols) << endl;
        }
    }
    return 0;
}