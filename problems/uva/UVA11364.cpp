#include <iostream>

using namespace std;

void run()
{
    int n_shops;
    cin >> n_shops;

    int low, high, value;
    for (int i = 0; i < n_shops; i++) {
        cin >> value;
        if (i == 0) {
            low = value;
            high = value;
        } else {
            if (value < low) {
                low = value;
            }

            if (value > high) {
                high = value;
            }
        }
    }

    cout << (high - low) * 2 << endl;

}

int main()
{
    int n;
    cin >> n;
    while(n--) run();
    return 0;
}