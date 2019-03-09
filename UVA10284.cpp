#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

// TODO: finish this time waster

using namespace std;

int board[64];
int safe_spots[64];

void attack(int i) {
    char c = (char) board[i];
    switch (c) {
        case 'p':
            break;
        case 'P':
            break;
        // TODO: etc..
    }
}

int main() {
    int count;
    string tmp;
    while (getline(cin, tmp)) {
        fill(board, board + 64, 0); // reset the board
        fill(safe_spots, safe_spots + 64, 1); // reset the safe spots board
        int i = 0;
        for (char c: tmp) {
            if (isdigit(c)) {
                i += c - '0';
            } else if (c != '/') {
                board[i] = c;
                i++;
            }
        }

        for (int i = 0; i < 64; i++) {
            if (board[i] != 0) attack(i);
        }

        count = 0;
        for (int i = 0; i < 64; i++) {
            if (board[i] == 0 && safe_spots[i] == 1) count++;
        }
        cout << count;
    }
    return 0;
}