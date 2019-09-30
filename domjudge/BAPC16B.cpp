#include <bits/stdc++.h>
// todo: runerror
using namespace std;

bool check(char a, char b, char c) {
    string tmp;
    tmp += a;
    tmp += b;
    tmp += c;
    return (tmp == "BLR") || (tmp == "LBR") || (tmp == "RBL") || (tmp == "BRL") || (tmp == "LRB") || (tmp == "RLB");
}

int main() {
    string s;
    cin >> s;
    string out;
    vector<int> matches;
    int i = 0;
    if (s.length() >= 3) {
        while (i < s.length() - 2) {
            if (check(s.at(i), s.at(i+1), s.at(i+2))) {
                matches.push_back(i);
                i += 3;
            } else {
                i++;
            }
        }
    }

    i = 0;
    int j = 0;
    bool skip = false;
    while (i < s.length()) {
        if (j < matches.size()) {
            if (matches[j] == i) {
                out += 'C';
                j++;
                i += 3;
                skip = true;
            }
        }

        if (!skip) {
            if (s.at(i) == 'R') {
                out += 'S';
            } else if (s.at(i) == 'B') {
                out += 'K';
            } else {
                out += 'H';
            }
            i++;
        } else {
            skip = false;
        }

    }

    cout << out << endl;
    return 0;
}