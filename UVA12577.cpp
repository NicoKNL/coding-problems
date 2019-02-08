#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int case_number = 1;
    while (true) {
        cin >> s;
        if (s == "*") break;

        if (s == "Hajj") {
            cout << "Case " << case_number << ": " << "Hajj-e-Akbar" << endl;
        } else { // if (s == "Umrah") {
            cout << "Case " << case_number << ": " << "Hajj-e-Asghar" << endl;
        }
        case_number++;
    }
    return 0;
}