#include <bits/stdc++.h>
using namespace std;

string s;

string spaceless(string line)
{
    string result = "";
    for (char c : line) {
        if (c != ' ') result += c;
    }
    return result;
}

void trim(int & lo, int & hi)
{
    // cout << "simplifying: " << lo << ", " << hi << endl;
    if (s[lo] == '(' && s[hi] == ')') {
        s.erase(s.begin() + hi);
        s.erase(s.begin() + lo);
        hi -= 2;
        // cout << "new s: " << s << ", |" << s[lo] << ", " << s[hi] << "|" << endl;
    }
}

void simplify_vector(vector<string> & seq, string op)
{
    bool done = false;
    while(!done) {
        done = true;
        for (int i = 0; i < seq.size(); ++i) {
            if (seq[i] == op) {
                uint64_t a = stoull(seq[i - 1]);
                uint64_t b = stoull(seq[i + 1]);
                // cout << a << ", " << b << endl;
                seq.erase(seq.begin() + i - 1, seq.begin() + i + 2);
                // cout << "erased" << endl;
                if (op == "*") {
                    a *= b;
                } else if (op == "+") {
                    a += b;
                }
                seq.insert(seq.begin() + i - 1, to_string(a));
                // cout << "inserted" << endl;
                done = false;
                break;
            }
        }
    }
}

void simplify(int lo, int hi)
{
    trim(lo, hi);

    vector<string> seq;
    string sub = "";
    for (int i = lo; i <= hi; ++i) {
        if (s[i] == '*') {
            seq.push_back(sub);
            seq.push_back("*");
            sub = "";
        } else if (s[i] == '+') {
            seq.push_back(sub);
            seq.push_back("+");
            sub = "";
        } else {
            sub += s[i];
        }
    }
    seq.push_back(sub);

    // for (string each : seq) {
    //     cout << "'" << each << "', ";
    // }
    // cout << endl;

    simplify_vector(seq, "+");
    // cout << "add done" << endl;
    // for (string each : seq) {
    //     cout << "'" << each << "', ";
    // }
    // cout << endl;

    simplify_vector(seq, "*");
    // cout << "mult done" << endl;
    // for (string each : seq) {
    //     cout << "'" << each << "', ";
    // }
    // cout << endl;

    s.replace(s.begin() + lo, s.begin() + hi + 1, seq[0]);
}

void resolve()
{
    bool resolved = false;
    while (!resolved) {
        cout << "s: " << s << endl;
        resolved = true;
        int open = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                open = i;
            } else if (s[i] == ')') {
                simplify(open, i);
                resolved = false;
                break;
            }
        }
    }

    simplify(0, s.length() - 1);
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
        cout << "----------------------" << endl;
        s = spaceless(line);
        resolve();
        cout << s << endl;
        sum += stoull(s);
    }
    cout << "SUM: " << sum << endl;
}
