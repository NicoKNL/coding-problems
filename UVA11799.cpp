#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int case_number = 1;
    while (n--) {
        int students;
        cin >> students;
        long int max = 0;
        long int speed;
        for (int s = 0; s < students; s++) {
            cin >> speed;
            if (speed > max) {
                max = speed;
            }
        }
        cout << "Case " << case_number << ": " << max << endl;
        case_number++;
    }

    return 0;
}