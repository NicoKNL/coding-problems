#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    long int sum = 0;
    string s;
    while (n--) {
        cin >> s;
        if (s == "donate") {
            long int donation;
            cin >> donation;
            sum += donation;
        } else { // "report"
            cout << sum << endl;
        }
    }
}