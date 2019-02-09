#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int case_number = 1;
    while (n--) {
        int walls;
        cin >> walls;
        int height, next_height;
        int low = 0;
        int high = 0;
        for (int w = 0; w < walls; w++) {
            if (w == 0) {
                cin >> height;
            } else {
                cin >> next_height;
                if (next_height > height) {
                    high++;
                } else if (next_height < height) {
                    low++;
                } else {
                    continue;
                }
                height = next_height;
            }
        }

        cout << "Case " << case_number << ": " << high << " " << low << endl;
        case_number++;
    }

    return 0;
}