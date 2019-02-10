#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int instructions;
        cin >> instructions;

        int x = 0;
        string instruction;
        int move[instructions];
        for (int i = 0; i < instructions; i++) {
            cin >> instruction;
            if (instruction == "LEFT") {
                move[i] = -1;
                x--;
            } else if (instruction == "RIGHT") {
                move[i] = 1;
                x++;
            } else { // "SAME"
                cin >> instruction;
                int other;
                cin >> other;
                move[i] = move[other - 1];
                x += move[i];
            }
        }
        cout << x << endl;
    }
    return 0;
}