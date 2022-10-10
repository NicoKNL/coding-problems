#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    string time;
    int hours, minutes;
    double hours_angle, minutes_angle, result;
    while (getline(cin, time)) {
        hours = stoi(time.substr(0, time.find(":")));
        minutes = stoi(time.substr(time.find(":") + 1));
        if (hours == 0 && minutes == 0) break;

        hours_angle = (double) hours * 30.0 + 30.0 * (double) minutes / 60.0;
        minutes_angle = (double) minutes * 6.0;
        result = min(abs(hours_angle - minutes_angle), abs(minutes_angle - hours_angle));
        result = min(result, abs(360.0 - result));
        cout << fixed << setprecision(3) << result << endl;
    }
    return 0;
}