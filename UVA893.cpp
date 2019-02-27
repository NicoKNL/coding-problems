#include <iostream>
// TODO: finish
using namespace std;
int leap[] = {-1000000, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int nonleap[] = {-1000000, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isLeapYear(int year) {
    bool divBy4 = year % 4 == 0;
    bool divBy100 = year % 100 == 0;
    bool divBy400 = year % 400 == 0;
    if ((divBy4 && !divBy100) || divBy400) return true;
    else return false;
}

int main() {
    int future, day, month, year;
    while (cin >> future >> day >> month >> year) {
        if (future == 0 && day == 0 && month == 0 && year == 0) break;
        while (future > 400) {
            if (future > 365 && isLeapYear(year)) {
                year++;
                future -= 366;
                day--;
            } else if (future > 364 && !isLeapYear(year)) {
                year++;
                future -= 365;
            }
        }
        while (future > 0) {
            if (future > 30) {
                if (isLeapYear(year)) {
                    future -= leap[month];
                } else {
                    future -= nonleap[month];
                }
                month++;
                if (month == 13) {
                    year++;
                    month = 1;
                }
            } else {
                future -= 1;
                day++;
                if (isLeapYear(year)) {
                    if (day > leap[month]) {
                        month++;
                        day = 1;
                    }
                } else {
                    if (day > nonleap[month]) {
                        month++;
                        day = 1;
                    }
                }
                if (month > 12) {
                    year++;
                    month = 1;
                }
            }
        }
        cout << day << " " << month << " " << year << endl;
    }
}