#include <bits/stdc++.h>
using namespace std;

int main() {
    // grab input file
    ifstream infile("../advent-of-code-2020/input/05.txt");
    if (!infile.is_open()) {
        return -1;
    }

    int max_seat = 0;

    string line = "";
    while (getline(infile, line)) {
        unsigned int row = 0;
        unsigned int col = 0;
        for (int i = 0; i < 7; ++i) {
            if (line[i] == 'B') row += (1 << (6 - i));
        }
        for (int i = 7; i < 10; ++i) {
            if (line[i] == 'R') col += (1 << (9 - i));
        }

        max_seat = max((int)(row * 8 + col), max_seat);
    }
    
    printf("%d", max_seat);
}
