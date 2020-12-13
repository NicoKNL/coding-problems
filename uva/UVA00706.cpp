#include <bits/stdc++.h>

using namespace std;

vector<char> one = {
        ' ', ' ', '|',
             ' ',
        ' ', ' ', '|',
};

vector<char> two = {
        ' ', '-', '|',
             '-',
        '|', '-', ' ',
};

vector<char> three = {
        ' ', '-', '|',
             '-',
        ' ', '-', '|',
};

vector<char> four = {
        '|', ' ', '|',
             '-',
        ' ', ' ', '|',
};

vector<char> five = {
        '|', '-', ' ',
             '-',
        ' ', '-', '|',
};

vector<char> six = {
        '|', '-', ' ',
             '-',
        '|', '-', '|',
};

vector<char> seven = {
        ' ', '-', '|',
             ' ',
        ' ', ' ', '|',
};

vector<char> eight = {
        '|', '-', '|',
             '-',
        '|', '-', '|',
};

vector<char> nine = {
        '|', '-', '|',
             '-',
        ' ', '-', '|',
};

vector<char> zero = {
        '|', '-', '|',
             ' ',
        '|', '-', '|',
};
map<char, vector<char>> M = {
        {'0', zero},
        {'1', one},
        {'2', two},
        {'3', three},
        {'4', four},
        {'5', five},
        {'6', six},
        {'7', seven},
        {'8', eight},
        {'9', nine},
};

int main() {
    int S;
    string N;
    int cases = 0;
    while (cin >> S >> N) {
        if (S == 0 && N == "0") break;
//        if (cases > 0) {
//        }
        vector<string> display(2 * S + 3);
        for (int i = 0; i < 2 * S + 3; i++) {
            for (char c : N) {
                if (i == 0) {
                    display[i] += ' ';
                    for (int k = 0; k < S; k++) {
                        display[i] += M[c][1];
                    }
                    display[i] += ' ';
                } else if (i < (2 * S + 3) / 2) {
                    display[i] += M[c][0];
                    for (int k = 0; k < S; k++) {
                        display[i] += ' ';
                    }
                    display[i] += M[c][2];
                } else if (i == (2 * S + 3) / 2) {
                    display[i] += ' ';
                    for (int k = 0; k < S; k++) {
                        display[i] += M[c][3];
                    }
                    display[i] += ' ';
                } else if (i == (2 * S + 2)) {
                    display[i] += ' ';
                    for (int k = 0; k < S; k++) {
                        display[i] += M[c][5];
                    }
                    display[i] += ' ';
                } else {
                    display[i] += M[c][4];
                    for (int k = 0; k < S; k++) {
                        display[i] += ' ';
                    }
                    display[i] += M[c][6];
                }
                display[i] += ' ';
            }
        }

        for (string line : display) {
            cout << line.substr(0, line.size() - 1) << endl;
        }
        cout << endl;

        cases++;
    }
    return 0;
}