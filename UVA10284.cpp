#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int board[64];
int safe_spots[64];

void attack(int i) {
    char c = (char) board[i];
    int tmp;
    safe_spots[i] = 0;
    switch (c) {
        case 'p': // Black pawns
            if (i + 9 < 64 && i % 8 != 7) safe_spots[i + 9] = 0;
            if (i + 7 < 64 && i % 8 != 0) safe_spots[i + 7] = 0;
            break;
        case 'P': // White pawns
            if (i - 9 >= 0 && i % 8 != 0) safe_spots[i - 9] = 0;
            if (i - 7 >= 0 && i % 8 != 7) safe_spots[i - 7] = 0;
            break;
        case 'n':
        case 'N': // Knights
            // left
            if (i - 17 >= 0 && i % 8 > 0) safe_spots[i - 17] = 0;
            if (i - 10 >= 0 && i % 8 > 1) safe_spots[i - 10] = 0;
            if (i + 6 < 64 && i % 8 > 1) safe_spots[i + 6] = 0;
            if (i + 15 < 64 && i % 8 > 0) safe_spots[i + 15] = 0;
            // right
            if (i - 15 >= 0 && i % 8 < 7) safe_spots[i - 15] = 0;
            if (i - 6 >= 0 && i % 8 < 6) safe_spots[i - 6] = 0;
            if (i + 10 < 64 && i % 8 < 6) safe_spots[i + 10] = 0;
            if (i + 17 < 64 && i % 8 < 7) safe_spots[i + 17] = 0;
            break;
        case 'b':
        case 'B': // Bishops
            tmp = i - 7;
            while (tmp >= 0 && tmp % 8 != 0 && board[tmp] == 0) { // Diag up right
                safe_spots[tmp] = 0;
                tmp -= 7;
            }

            tmp = i - 9;
            while (tmp >= 0 && tmp % 8 != 7 && board[tmp] == 0) { // Diag up left
                safe_spots[tmp] = 0;
                tmp -= 9;
            }

            tmp = i + 9;
            while (tmp < 64 && tmp % 8 != 0 && board[tmp] == 0) { // Diag down right
                safe_spots[tmp] = 0;
                tmp += 9;
            }

            tmp = i + 7;
            while (tmp < 64 && tmp % 8 != 7 && board[tmp] == 0) { // Diag down left
                safe_spots[tmp] = 0;
                tmp += 7;
            }
            break;
        case 'r':
        case 'R': // Rooks
            tmp = i + 1;
            while (tmp < 64 && tmp % 8 != 0 && board[tmp] == 0) { // Right
                safe_spots[tmp] = 0;
                tmp += 1;
            }

            tmp = i - 1;
            while (tmp >= 0 && tmp % 8 != 7 && board[tmp] == 0) { // Left
                safe_spots[tmp] = 0;
                tmp -= 1;
            }

            tmp = i - 8;
            while (tmp >= 0 && board[tmp] == 0) { // Up
                safe_spots[tmp] = 0;
                tmp -= 8;
            }

            tmp = i + 8;
            while (tmp < 64 && board[tmp] == 0) { // Down
                safe_spots[tmp] = 0;
                tmp += 8;
            }
            break;
        case 'q':
        case 'Q': // Queens
            board[i] = 'R';
            attack(i); // Attack from this pos as rook
            board[i] = 'B';
            attack(i); // Attack from this pos as bishop
            board[i] = 'Q'; // Restore original board piece
            break;
        case 'k':
        case 'K': // Kings
            // HORIZONTAL
            tmp = i + 1;
            if (tmp < 64 && tmp % 8 != 0) safe_spots[tmp] = 0;
            tmp = i - 1;
            if (tmp >= 0 && tmp % 8 != 7) safe_spots[tmp] = 0;
            tmp = i - 8;
            if (tmp >= 0) safe_spots[tmp] = 0;
            tmp = i + 8;
            if (tmp < 64) safe_spots[tmp] = 0;
            // DIAG
            tmp = i - 7;
            if (tmp >= 0 && tmp % 8 != 0) safe_spots[tmp] = 0;
            tmp = i - 9;
            if (tmp >= 0 && tmp % 8 != 7) safe_spots[tmp] = 0;
            tmp = i + 9;
            if (tmp < 64 && tmp % 8 != 0) safe_spots[tmp] = 0;
            tmp = i + 7;
            if (tmp < 64 && tmp % 8 != 7) safe_spots[tmp] = 0;
            break;
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
        cout << count << endl;
    }
    return 0;
}