#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string urls[10];
    int values[10];
    int case_number = 1;
    while (n--) {
        cout << "Case #" << case_number << ":" << endl;
        int max_value = -1;
        for (int i = 0; i < 10; i++) {
            cin >> urls[i] >> values[i];
            if (values[i] > max_value) {
                max_value = values[i];
            }
        }

        for (int i = 0; i < 10; i++) {
            if (values[i] == max_value) {
                cout << urls[i] << endl;
            }
        }

        case_number++;
    }
}