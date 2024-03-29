#include <bits/stdc++.h>
using namespace std;

int main() {
    // grab input file
    ifstream infile("../advent-of-code-2019/input/01.txt");
    if (!infile.is_open()) {
        return -1;
    }

    long long total_fuel = 0;
    double fuel;

    string line = "";
    while (getline(infile, line)) {
        stringstream ss(line);
        long long value;
        ss >> value;

        while (value > 0) {
            fuel = floor((double) value / 3.0) - 2.0;
            if (fuel > 0) {
                total_fuel += (long long) fuel;
                value = (long long) fuel;
            }

            if (fuel <= 0) break;
        }
    }
    printf("%lld", total_fuel);
}
