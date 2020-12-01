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
        long long remainder = 2020 - value;
        for (long long value2 : values) {
            if (values.find(remainder - value2) != values.end()) {
                printf("Answer: %lld\n", value * value2 * (remainder - value2));
                break;
            }
        }
    }
}
