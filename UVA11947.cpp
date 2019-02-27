#include <iostream>

using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int n;
    cin >> n;
    string s;
    int day, month, year;
    while (n--) {
        cin >> s;
        day = stoi(s.substr(2, 2));
        month = stoi(s.substr(0, 2));
        year = stoi(s.substr(4));
        cout << isLeapYear(year) << endl;
    }
    return 0;
}