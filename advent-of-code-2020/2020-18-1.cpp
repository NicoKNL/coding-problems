#include <bits/stdc++.h>
using namespace std;

stack<pair<char, uint64_t>> Q;

uint64_t solve(string s) 
{
    cout << s << endl;
    uint64_t result = 0;
    char op = '-';
    for (int i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (c == ' ') {
            continue;
        } else if (c == '(') {
            for (int j = 0; j <= Q.size(); ++j) cout << "  ";
            cout << "add: " << op << " " << result << endl;
            Q.push({op, result});
            op = '-';
            result = 0;
        } else if (c == ')') {
            for (int j = 0; j < Q.size(); ++j) cout << "  ";
            pair<char, uint64_t> prev = Q.top(); Q.pop();
            cout << "pop: " << prev.first << " " << prev.second << endl;
            
            if (prev.first == '*') {
                result *= prev.second;
            } else if (prev.first == '+') {
                result += prev.second;
            }
            op = prev.first;
        } else if (c == '*' || c == '+') {
            op = c;
        } else { // value
            if (op == '-') {
                result = c - '0';
            } else if (op == '*') {
                result *= c - '0';
            } else if (op == '+') {
                result += c - '0';
            }
        }
    }
    return result;
}

int main() 
{
    // grab input file
    ifstream infile ("../advent-of-code-2020/input/18.txt");
    if (!infile.is_open()) {
        return -1;
    }

    string line = "";
    uint64_t sum = 0;
    while (getline(infile, line)) {
        uint64_t result = solve(line);
        sum += result;
        cout << result << endl;
    }
    cout << sum << endl;
}
