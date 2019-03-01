#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

// TODO: cleanup file

using namespace std;
vector<string> validSequences;
vector<string> possibleSequences;
string source, target;

void stackSim2(const string& s, const string& t, int i, int j, stack<char> stk, string seq) {
    stack<char> stk2 = stk;
    if (i < s.length()) {
        stk2.push(s.at(i));
        stackSim2(s, t, i + 1, j, stk2, seq + "i");
    }

    if (j < i) {
        if (t.at(j) == stk.top()) {
            stk.pop();
            stackSim2(s, t, i, j + 1, stk, seq + "o");
        }
    }

    if (i == j && i == s.length()) {
        validSequences.push_back(seq);
    }
}

bool matches(string a, string b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

bool stackSim(string s, string t, string seq) {
    stack<char> stk;
    int i = 0;
    int j = 0;
    for (char c: seq) {
        if (c == 'i') {
            stk.push(s.at(i));
            i++;
        }

        if (c == 'o') {
            if (stk.empty()) {
                return false;
            } else {
                c = stk.top();
                if (c != t.at(j)) {
                    return false;
                }

                stk.pop();
                j++;
            }
        }
    }
    return true;
}

void output(string s) {
    for (int i = 0; i < s.length(); i++) {
        cout << s.at(i);
        if (i < s.length() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

void allPossibleSequences(string seq, int i, int j, int limit) {
    if (!stackSim(source, target, seq)) return;

    if (i == limit && j == limit) {
        possibleSequences.push_back(seq);
    }

    if (i < limit) {
        allPossibleSequences(seq + "i", i + 1, j, limit);
    }

    if (j < i) {
        allPossibleSequences(seq + "o", i, j + 1, limit);
    }
}

int main() {
    while (getline(cin, source)) {
        getline(cin, target);

        validSequences.clear();
        possibleSequences.clear();

        if (matches(source, target)) {
            string sequence;
            allPossibleSequences("", 0, 0, source.length());

            for (string seq: possibleSequences) {
                if (stackSim(source, target, seq)) {
                    validSequences.push_back(seq);
                }
            }
        }

        cout << "[" << endl;
        for (string seq: validSequences) {
            output(seq);
        }
        cout << "]" << endl;
    }
    return 0;
}