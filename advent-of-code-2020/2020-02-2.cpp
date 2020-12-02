#include <bits/stdc++.h>
using namespace std;

int main() {
    // grab input file
    ifstream infile("../advent-of-code-2020/input/02.txt");
    if (!infile.is_open()) {
        return -1;
    }

    int valid = 0;

    string line = "";
    while (getline(infile, line)) {
        int pos_a = stoi(line.substr(0, line.find("-")));
        line.erase(0, line.find("-") + 1);

        int pos_b = stoi(line.substr(0, line.find(" ")));
        line.erase(0, line.find(" ") + 1);

        char c = line[0];
        line.erase(0, line.find(" ") + 1);

        bool at_a = line[pos_a - 1] == c;
        bool at_b = line[pos_b - 1] == c;
        if (at_a ^ at_b) ++valid;
    }

    printf("Valid: %d", valid);
}
