#include <bits/stdc++.h>
using namespace std;

int main() {
    // grab input file
    ifstream infile("../advent-of-code-2019/input/02.txt");
    if (!infile.is_open()) {
        return -1;
    }

    vector<long long> integers;
    vector<long long> default_integers;
    string line = "";
    while (getline(infile, line, ',')) {
        stringstream ss(line);
        int i;
        while (ss >> i) {
            integers.emplace_back(i);
        }
    }

    default_integers = integers;

    bool found = false;

    for (int noun = 0; noun <= 99 && !found; ++noun) {
        for (int verb = 0; verb <= 99 && !found; ++verb) {
            integers = default_integers;
            integers[1] = noun;
            integers[2] = verb;

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
            if (integers[0] == 19690720) {
                cout << 100 * noun + verb << endl;
                found = true;
            }
        }
    }
}
