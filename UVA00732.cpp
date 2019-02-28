#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void show(string s) {
    for (int i = 0; i < s.length(); i++) {
        cout << s.at(i);
        if (i < s.length() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

void dfsStackSim(stack<char> stk, string s, string t, string current) {
    if (s.length() > 0) { // i
        return dfsStackSim(stk, s, t, current);
    }
    if (t.length() > 0) { // o
        if (!stk.empty()) {
            stk.pop();
        }
    }
}

// o o o i i i
// o i o i o i

int main() {
    string source, target;
    vector<string> valid_ops;
    stack<char> s;
    while (getline(cin, source)) {
        getline(cin, target);
        valid_ops.clear();
        cout << source << " >> " << target << endl;



        sort(valid_ops.begin(), valid_ops.end());
        cout << "[" << endl;
        for (string op: valid_ops) {
            show(op);
        }
        cout << "]" << endl;
    }
    return 0;
}