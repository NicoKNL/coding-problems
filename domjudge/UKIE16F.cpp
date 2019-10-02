#include <bits/stdc++.h>

using namespace std;

void increment(string & s, int i) {
    if (i < 0) {
        s = "1" + s;
        return;
    }

    if (s.at(i) == '9') {
        s.at(i) = '0';
        increment(s, --i);
    } else {
        s.at(i) = s.at(i) + 1;
    }
}

int main() {
    string s;
    cin >> s;
    vector<int> digits(10); // 0 - 9
    for (char c: s) {
        digits[c - '0']++;
    }

    int minval = INT_MAX;
    int mindigit = -1;
    for (int i = 0; i < 10; i++) {
        if (digits[i] < minval) {
            minval = digits[i];
            mindigit = i;
        }
    }

    bool all_same = true;
    for (int i = 0; i < 10; i++) {
        if (digits[i] != minval) {
            all_same = false;
            break;
        }
    }

    if (all_same) minval++;

    string result;
    while (result.length() < minval) {
        for (int i = 1; i < 10; i++) {
            if (digits[i] > 0) {
                result += '0' + i;
                digits[i]--;
                break;
            }
        }
    }


    cout << result << endl;
    //  increment(s, s.length() - 1);
    // todo: every digit has some count, form numbers based on that and use increment()
    cout << s;
    return 0;
}