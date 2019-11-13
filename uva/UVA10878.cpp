#include <bits/stdc++.h>
using namespace std;

// todo: fix presentation error

int main() {
    string s, tmp;
    while (getline(cin, s)) {
        tmp = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') tmp += '0';
            if (s[i] == 'o') tmp += '1';
        }
        if (tmp != "") {
            cout << (char) stoi(tmp, 0, 2);
//            if (stoi(tmp, 0, 2) == 10) {
//                printf("\n");
//            }
        }

    }
    cout << endl;
    return 0;
}
