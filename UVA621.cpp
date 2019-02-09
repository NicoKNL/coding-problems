#include <iostream>
#include <string>

using namespace std;

void run() {
    string in;
    cin >> in;
    long int len = in.length();
    if (len < 3) {
        cout << "+" << endl;
    } else if (in.at(len - 2) == '3' && in.at(len - 1) == '5') {
        cout << "-" << endl;
    } else if (in.at(0) == '9' && in.at(len - 1) == '4') {
        cout << "*" << endl;
    } else {
        cout << "?" << endl;
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) run();
    return 0;
}