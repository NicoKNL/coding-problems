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
        int min_count = stoi(line.substr(0, line.find("-")));
        line.erase(0, line.find("-") + 1);

        int max_count = stoi(line.substr(0, line.find(" ")));
        line.erase(0, line.find(" ") + 1);

        char c = line[0];
        line.erase(0, line.find(" ") + 1);

        int char_count = 0;
        for (char cc : line) {
            if (cc == c) ++char_count;
        }

        if (min_count <= char_count && char_count <= max_count) ++valid;
    }

    printf("Valid: %d", valid);
}
