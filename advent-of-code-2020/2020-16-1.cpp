#include <bits/stdc++.h>
using namespace std;

#define lo first
#define hi second

int main() 
{
    // grab input file
    ifstream infile ("../advent-of-code-2020/input/16.txt");
    if (!infile.is_open()) {
        return -1;
    }

    vector<pair<int, int>> ranges;
    string line = "";
    int parse_state = 0;
    int valid = 0;
    int invalid = 0;
    while (getline(infile, line)) {
        cout << line << endl;
        if (line == "your ticket:") {
            parse_state = 1;
            continue;
        } else if (line == "nearby tickets:") {
            parse_state = 2;
            continue;
        }

        if (parse_state == 0) {
            regex regexp("[0-9]+-[0-9]+");
            smatch m;
            while (regex_search(line, m, regexp)) {
                for (string each : m) {
                    pair<int, int> range = {0, 0};
                    range.lo = stoi(each.substr(0, each.find("-")));
                    range.hi = stoi(each.substr(each.find("-") + 1));

                    bool sub = false; 
                    for (pair<int, int> & other : ranges) {
                        if (other.lo <= range.lo && range.lo <= other.hi) {
                            other.hi = max(other.hi, range.hi);
                            sub = true;
                        }

                        if (other.lo <= range.hi && range.hi <= other.hi) {
                            other.lo = min(other.lo, range.lo);
                            sub = true;
                        }
                    }
                    if (!sub) {
                        ranges.emplace_back(range);
                    }
                    cout << "each: " << range.lo << ", " << range.hi << " " << endl;
                }
                line = m.suffix().str();
            }
        } else if (parse_state == 2) {
            string svalue = "";
            stringstream ss(line);
            while (getline(ss, svalue, ',')) {
                int value = stoi(svalue);
                bool found = false;
                for (pair<int, int> & range : ranges) {
                    if (range.lo <= value && value <= range.hi) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    invalid += value;
                } 
            }
        }
    }
    cout << invalid << endl;
}
