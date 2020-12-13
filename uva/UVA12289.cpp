#include <iostream>
#include <string>

using namespace std;

void run() {
    string s;
    cin >> s;
    if (s.length() == 5) {
        cout << 3 << endl;
    } else {
        if (s.at(0) == 'o' || s.at(1) == 'n') {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) run();
    return 0;
}