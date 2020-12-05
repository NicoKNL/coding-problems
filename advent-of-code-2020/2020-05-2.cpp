#include <bits/stdc++.h>
using namespace std;

int main() {
    // grab input file
    ifstream infile("../advent-of-code-2020/input/05.txt");
    if (!infile.is_open()) {
        return -1;
    }

    vector<int> seats;
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
        seats.push_back((int)(row * 8 + col));
    }

    sort(seats.begin(), seats.end());
    int prev_seat = -1;
    for (int seat : seats) {
        if (prev_seat == -1) prev_seat = seat;
        if (seat - prev_seat > 1) cout << seat - 1 << endl;
        prev_seat = seat;
    } 
}
