#include <bits/stdc++.h>
using namespace std;

int main() {
    // grab input file
    ifstream infile ("../advent-of-code-2020/input/08.txt");
    if (!infile.is_open()) {
        return -1;
    }

    vector<pair<string, int>> instructions;
    vector<bool> executed;
    string line = "";
    while (getline(infile, line)) {
        string instr = line.substr(0, line.find(' ', 0));
        string offset = line.substr(line.find(' ') + 1);
        
        if (line.find('+') != string::npos) {
            offset = offset.substr(1);
        }

        instructions.emplace_back(make_pair(instr, stoi(offset)));
        executed.push_back(false);
    }

    long long acc = 0;
    int ip = 0;
    while (true) {
        if (executed[ip]) {
            break;
        } else {
            executed[ip] = true;
        }

        if (instructions[ip].first == "nop") {
            ++ip;
        } else if (instructions[ip].first == "acc") {
            acc += instructions[ip].second;
            ++ip;
        } else if (instructions[ip].first == "jmp") {
            ip += instructions[ip].second;
        }
    }

    cout << acc << endl;
}
