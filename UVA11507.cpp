#include <iostream>
#include <string>

using namespace std;

int main() {
    int length;
    string cmd;
    string dir;

    while (cin >> length) {
        if (length == 0) break;
        dir = "+x";

        while (--length) {
            cin >> cmd;
            if (cmd == "No") {
                continue;
            } else if (dir == "+x") {
                dir = cmd;
            } else if (dir == "-x") {
                char sign, axis;
                sign = cmd.at(0);
                axis = cmd.at(1);
                if (sign == '-') {
                    dir = "+";
                    dir += axis;
                } else {
                    dir = "-";
                    dir += axis;
                }
            } else {
                if (cmd == "+y") {
                    if (dir == "+y") {
                        dir = "-x";
                    } else if (dir == "-y") {
                        dir = "+x";
                    } else {
                        continue;
                    }
                } else if (cmd == "-y") {
                    if (dir == "+y") {
                        dir = "+x";
                    } else if (dir == "-y") {
                        dir = "-x";
                    } else {
                        continue;
                    }
                } else if (cmd == "+z") {
                    if (dir == "+z") {
                        dir = "-x";
                    } else if (dir == "-z") {
                        dir = "+x";
                    } else {
                        continue;
                    }
                } else { //if (cmd == "-z") {
                    if (dir == "+z") {
                        dir = "+x";
                    } else if (dir == "-z") {
                        dir = "-x";
                    } else {
                        continue;
                    }
                }
            }
        }
        cout << dir << endl;
    }
}