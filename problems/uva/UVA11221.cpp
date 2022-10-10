#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

string clean(string s) {
    string cleaned;
    for (char c: s) {
        if ('a' <= c && c <= 'z') cleaned += c;
    }
    return cleaned;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    string s;
    int case_number = 1;
    while (n--) {
        getline(cin, s);
        s = clean(s);

        int k = (int) sqrt(s.size());
        vector<vector<char>> square;

        int i = 0;
        for (int y = 0; y < k; y++) {
            square.push_back(vector<char> {});
            for (int x = 0; x < k; x++) {
                square.at(y).push_back(s.at(i));
                i++;
            }
        }

        bool magic = true;
        for (int y = 0; y < k; y++) {
            if (!magic) break;
            for (int x = 0; x < k; x++) {
                if (square.at(y).at(x) != square.at(k - y - 1).at(k - x - 1) ||
                    square.at(y).at(x) != square.at(x).at(y)) magic = false;
            }
        }

        cout << "Case #" << case_number << ":" << endl;
        if (magic && k * k == s.size()) {
            cout << k << endl;
        } else {
            cout << "No magic :(" << endl;
        }
        case_number++;
    }
}