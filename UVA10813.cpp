#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> card;

bool eval(int num) {
    // Row check
    bool bingo = false;
    for (int i = 0; i < 5; i++) {
        bingo = true;
        for (int j = 0; j < 5; j++) {
            if (card[i][j] == num) card[i][j] = -1; // Update the number before checking
            if (card[i][j] != -1) bingo = false;
        }
        if (bingo) return bingo;
    }

    // Column check
    for (int i = 0; i < 5; i++) {
        bingo = true;
        for (int j = 0; j < 5; j++) {
            if (card[j][i] != -1) bingo = false;
        }
        if (bingo) return bingo;
    }

    // Diag down check
    bingo = true;
    for (int i = 0; i < 5; i++) {
        if (card[i][i] != -1) {
            bingo = false;
            break;
        }
    }
    if (bingo) return bingo;

    // Diag up check
    bingo = true;
    for (int i = 0; i < 5; i++) {
        if (card[4 - i][i] != -1) {
            bingo = false;
            break;
        }
    }
    return bingo;
}

int main() {
    int n, tmp, turns;
    bool bingo;
    cin >> n;
    while (n--) {
        card.clear(); // Reset the card
        // Build the card
        for (int i = 0; i < 5; i++) {
            vector<int> row;
            for (int j = 0; j < 5; j++) {
                if (i == 2 && j == 2) {
                    row.push_back(-1);
                } else {
                    cin >> tmp;
                    row.push_back(tmp);
                }
            }
            card.push_back(row);
        }

        turns = 0;
        bingo = false;
        // Simulate the card
        for (int i = 0; i < 75; i++) {
            cin >> tmp;
            if (!bingo) {
                bingo = eval(tmp);
                turns++;
            }
        }

        cout << "BINGO after " << turns << " numbers announced" << endl;
    }
    return 0;
}