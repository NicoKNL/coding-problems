#include <iostream>

using namespace std;

int main() {
    long m, n, limit, size, line, column;
    while (cin >> m >> n) {
        if (m == 0 && n == 0) break;

        // Find upperbound ring
        int i = 1;
        for (; i < 50001; i++) {
            size = 2 * i - 1;
            limit = size * size;
            if (limit >= n) break;
        }


        // Figure out N/E/S/W
        int c = 0;
        while ((limit - (size - 1) > n)) {
            limit -= (size - 1);
            c++;
        }

        switch(c) {
            case 0:
                column = size;
                line = size - (limit - n);
                break;
            case 1:
                line = 1;
                column = size - (limit - n);
                break;
            case 2:
                column = 1;
                line = 1 + (limit - n);
                break;
            case 3:
                column = 1 + (limit - n);
                line = size;
                break;
        }

        column += (m - size) / 2;
        line += (m - size) / 2;
        cout << "Line = " << line << ", column = " << column << "." << endl;
    }
    return 0;
}