#include <iostream>

using namespace std;

int main() {
    int n, x, y, z;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> z;

        cout << "Case " << i + 1 << ": ";
        if (x > 20 || y > 20 || z > 20) {
            cout << "bad" << endl;
        } else {
            cout << "good" << endl;
        }
    }
    return 0;
}