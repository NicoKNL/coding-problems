#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n;
    string name, day, month, year, birthday;
    vector<string> birthdays;

    cin >> n;
    while (n--) {
        cin >> name >> day >> month >> year;

        /* prepend 0 if needed */
        if (day.size() < 2) day.insert(0, "0");
        if (month.size() < 2) month.insert(0, "0");

        birthday = year;
        birthday.append(month).append(day).append(name);
        birthdays.push_back(birthday);
    }

    sort(birthdays.begin(), birthdays.end());
    cout << birthdays.at(birthdays.size() - 1).substr(8) << endl; // .substr(8) to ignore the 8 numbers pertaining to the date
    cout << birthdays.at(0).substr(8) << endl;
    return 0;
}