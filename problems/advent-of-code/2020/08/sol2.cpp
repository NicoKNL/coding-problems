#include <bits/stdc++.h>
using namespace std;

vector<pair<string, int>> instructions;
vector<bool> executed;
long long acc = 0;
int ip = 0;

void reset()
{
    for (int i = 0; i < executed.size(); ++i) {
        executed[i] = false;
    }
    acc = 0;
    ip = 0;
}

int main() {
    // grab input file
    ifstream infile ("../advent-of-code-2020/input/08.txt");
    if (!infile.is_open()) {
        return -1;
    }

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

    int k = 0;
    for (auto instr: instructions) {
        if (instr.first == "acc") {
            ++k;
            continue;
        }
        cout << "--------" << endl;
        cout << instr.first << endl;
        reset();
        bool nop;
        if (instr.first == "jmp") {
            nop = false;
            instructions[k].first = "nop";
        } else {
            nop = true;
            instructions[k].first = "jmp";
        }
        cout << instructions[k].first << endl;
        cout << ip << ", " << acc << endl; 
        while (true) {
            if (ip == instructions.size()) {
                cout << acc << endl;
                return 0; // end program
            }
            if (executed[ip]) {
                cout << "resetting: " << ip << endl;
                // reset the instructions
                if (nop) {
                    instructions[k].first = "nop";
                } else {
                    instructions[k].first = "jmp";
                }
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
        ++k;
    }
}
