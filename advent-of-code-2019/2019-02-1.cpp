#include <bits/stdc++.h>
using namespace std;

int main() {
    // grab input file
    ifstream infile("../advent-of-code-2019/input/02.txt");
    if (!infile.is_open()) {
        return -1;
    }

    vector<long long> integers;
    string line = "";
    while (getline(infile, line, ',')) {
        stringstream ss(line);
        int i;
        while (ss >> i) {
            integers.emplace_back(i);
        }
    }

    integers[1] = 12;
    integers[2] = 2;

    bool halt = false;
    for (int i = 0; i < integers.size() && !halt; i += 4) {
        long long opcode = integers[i];
        long long a = integers[integers[i + 1]];
        long long b = integers[integers[i + 2]];

        switch (opcode) {
            case 1:
                integers[integers[i + 3]] = a + b;
                break;
            case 2:
                integers[integers[i + 3]] = a * b;
                break;
            case 99:
                halt = true;
                break;
        }
    }

    cout << integers[0] << endl;
}
