#include <bits/stdc++.h>
using namespace std;

int main() 
{
    // grab input file
    ifstream infile ("../advent-of-code-2020/input/16.txt");
    if (!infile.is_open()) {
        return -1;
    }
    vector<int> lo;
    vector<int> hi;
    vector<int> my_ticket;
    vector<vector<int>> tickets;
    int range_count;

    string line = "";
    int parse_state = 0;
    while (getline(infile, line)) {
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
                    int l = stoi(each.substr(0, each.find("-")));
                    lo.emplace_back(l);

                    int h = stoi(each.substr(each.find("-") + 1));
                    hi.emplace_back(h);
                    ++range_count;
                }
                line = m.suffix().str();
            }
        } else if (parse_state == 1) {
            string svalue = "";
            stringstream ss(line);
            while (getline(ss, svalue, ',')) {
                int value = stoi(svalue);
                my_ticket.emplace_back(value);
            }
        } else if (parse_state == 2) {
            vector<int> ticket;

            string svalue = "";
            stringstream ss(line);
            bool valid_ticket = false;
            while (getline(ss, svalue, ',')) {
                int value = stoi(svalue);

                valid_ticket = false;
                for (int i = 0; i < range_count; i += 2) {
                    if ((lo[i] <= value && value <= hi[i]) || (lo[i + 1] <= value && value <= hi[i + 1])) {
                        ticket.emplace_back(value);
                        valid_ticket = true;
                        break;
                    } 
                }

                if (!valid_ticket) {
                    break;
                }
            }

            if (valid_ticket) {
                tickets.emplace_back(ticket);
            } 
        }
    }

    tickets.push_back(my_ticket);

    vector<int> counter(20, 0);

    for (int i = 0; i < range_count; i += 2) {
        bool valid;
        for (int f = 0; f < tickets[0].size(); ++f) {
            valid = true;
            for (int t = 0; t < tickets.size(); ++t) {
                if (!((lo[i] <= tickets[t][f] && tickets[t][f] <= hi[i]) || (lo[i + 1] <= tickets[t][f] && tickets[t][f] <= hi[i + 1]))) {
                    valid = false;
                    break;
                }    
            }
            if (valid) {
                ++counter[i / 2];
            }
        }
    }

    for (int count : counter) {
        cout << count << ", ";
    }
    cout << endl;

    vector<int> mapping(20, -1);
    vector<bool> taken(20, false);
    int target = 1;
    while (target <= 20) {
        for (int i = 0; i < counter.size(); ++i) {
            if (counter[i] != target) continue;

            bool valid;
            for (int f = 0; f < tickets[0].size(); ++f) {
                if (taken[f]) continue;
                valid = true;
                for (int t = 0; t < tickets.size(); ++t) {
                    if (!((lo[2 * i] <= tickets[t][f] && tickets[t][f] <= hi[2 * i]) || (lo[2 * i + 1] <= tickets[t][f] && tickets[t][f] <= hi[2 * i + 1]))) {
                        valid = false;
                        break;
                    }    
                }

                if (valid) {
                    mapping[i] = f;
                    taken[f] = true;
                    goto next_target;
                }
            }
        }
        next_target: ++target;
    }

    // Sum and output result
    uint64_t result = 1;
    for (int i = 0; i < 6; ++i) {
        cout << my_ticket[mapping[i]] << " * ";
        result *= (uint64_t) my_ticket[mapping[i]];
    }
    cout << result << endl;
}
