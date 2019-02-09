#include <iostream>
#include <string>

using namespace std;

void sumify(string in) {
    if (in.length() == 1) {
        cout << in << endl;
        return;
    } else {
        int sum = 0;
        for (int i = 0; i < in.length(); i++) {
            sum += in.at(i) - '0';
        }
        return sumify(to_string(sum));
    }
}

int main() {
    string in;
    while(true) {
        cin >> in;
        if (in == "0") {
            break;
        }

        sumify(in);
    }
    return 0;
}