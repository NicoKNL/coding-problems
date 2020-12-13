#include <iostream>

using namespace std;

int main() {
    int n;
    int case_number = 1;
    while (true) {
        cin >> n;
        if (n == 0) break;

        int result = 0;
        int val;
        for (int i = 0; i < n; i++) {
            cin >> val;
            if (val > 0) {
                result++;
            } else {
                result--;
            }
        }
        cout << "Case " << case_number << ": " << result << endl;
        case_number++;
    }

    return 0;
}