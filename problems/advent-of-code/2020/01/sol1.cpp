#include <bits/stdc++.h>
using namespace std;

int main() {
    // grab input file
    ifstream infile("../advent-of-code-2020/input/01.txt");
    if (!infile.is_open()) {
        return -1;
    }

    set<long long> values;

    string line = "";
    while (getline(infile, line)) {
        stringstream ss(line);
        long long value;
        ss >> value;
        values.insert(value);
    }

    for (long long value : values) {
        if (values.find(2020 - value) != values.end()) {
            printf("Answer: %lld\n", value * (2020 - value));
            break;
        }
    }
}
