#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int case_number = 1;
    while (n--) {
        int calls;
        cin >> calls;

        long int mile = 0;
        long int juice = 0;
        int length;
        for (int c = 0; c < calls; c++) {
            cin >> length;
            mile += (length / 30) * 10 + 10;
            juice += (length / 60) * 15 + 15;
        }

        cout << "Case " << case_number << ": ";

        if (mile <= juice) {
            cout << "Mile ";
        }
        if (juice <= mile) {
            cout << "Juice ";
        }

        cout << min(mile, juice) << endl;
        case_number++;
    }
    return 0;
}