#include <bits/stdc++.h>
using namespace std;

#define lo first
#define hi second

bool inRange(pair<int, int> range, int value)
{
    return range.lo <= value && value <= range.hi;
}

int main() 
{
    // grab input file
    ifstream infile ("../advent-of-code-2020/input/16 copy.txt");
    if (!infile.is_open()) {
        return -1;
    }
    vector<pair<int, int>> ranges;
    vector<pair<int, vector<int>>> my_ticket;
    vector<vector<pair<int, vector<int>>>> tickets;
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
                    pair<int, int> range = {0, 0};
                    range.lo = stoi(each.substr(0, each.find("-")));
                    range.hi = stoi(each.substr(each.find("-") + 1));
                    ranges.emplace_back(range);
                }
                line = m.suffix().str();
            }
        } else if (parse_state == 1) {
            string svalue = "";
            stringstream ss(line);
            vector<pair<int, vector<int>>> ticket;
            while (getline(ss, svalue, ',')) {
                vector<int> valid_ranges;
                int value = stoi(svalue);
                for (int i = 0; i < ranges.size(); ++i) {
                    pair<int, int> range = ranges[i];
                    if (range.lo <= value && value <= range.hi) {
                        valid_ranges.emplace_back(i);
                    }
                }
                my_ticket.push_back({value, valid_ranges});
            }
        } else if (parse_state == 2) {
            string svalue = "";
            stringstream ss(line);
            bool valid;
            vector<pair<int, vector<int>>> ticket;
            while (getline(ss, svalue, ',')) {
                vector<int> valid_ranges;
                int value = stoi(svalue);
                valid = true;
                bool found = false;
                for (int i = 0; i < ranges.size(); ++i) {
                    pair<int, int> range = ranges[i];
                    if (range.lo <= value && value <= range.hi) {
                        found = true;
                        valid_ranges.emplace_back(i);
                    }
                }
                if (!found) {
                    valid = false;
                    break;
                } else {
                    ticket.push_back({value, valid_ranges});
                }
            }
            if (valid) {
                tickets.emplace_back(ticket);
            }
        }
    }
    tickets.push_back(my_ticket);

    vector<bool> taken(ranges.size() / 2, false);
    vector<int> mapping(ranges.size() / 2, -1);
    int target_count = 1;
    while (true) {
        cout << "Loooooop: " << target_count << "---------------------------------" << endl;
        bool done = true;
        for (auto m : mapping) {
            cout << m << " ";
            if (m == -1) {
                done = false;
            }
        }
        cout << endl;
        if (done) break;
        bool found = false;

        for (int i = 0; i < ranges.size() / 2; ++i) {
            cout << "  Considering range: " << i << endl;
            pair<int, int> range_a = ranges[i];
            pair<int, int> range_b = ranges[i + 1];

            vector<int> candidate_fields;
            for (int field = 0; field < my_ticket.size(); ++field) {
                cout << "    Field: " << field;
                if (taken[field]) {
                    cout << " is already taken." << endl;
                    continue;
                }

                bool match_all = true;            
                for (auto ticket : tickets) {
                    if (!(inRange(range_a, ticket[i].first) || inRange(range_b, ticket[i].first))) {
                        match_all = false;
                    }
                }
                
                // debug
                if (match_all) {
                    cout << " matches for all tickets." << endl;
                } else {
                    cout << " doesn't match for all tickets." << endl;
                }

                if (match_all) candidate_fields.emplace_back(field);
            }
            cout << "      matchcount " << candidate_fields.size();

            // debug
            if (candidate_fields.size() <= target_count) {
                cout << " and matches " << target_count << endl;
            } else {
                cout << " and doesn't match with " << candidate_fields.size() << " against " << target_count << endl;
            }
            if (candidate_fields.size() <= target_count) {
                for (int candidate : candidate_fields) {
                    if (!taken[candidate]) {
                        taken[candidate] = true;
                        found = true;
                        mapping[i] = candidate;
                        break;
                    }
                }
            }
        }
        if (!found) ++target_count;
    }

    // int target_count = 1;
    // cout << "ticket count: " << tickets.size() << endl;
    // while (true) {
    //     bool done = true;
    //     cout << "current mapping: ";
    //     for (auto m : mapping) {
    //         cout << m << " ";
    //         if (m == -1) {
    //             done = false;
    //         }
    //     }
    //     cout << endl;
    //     if (done) break;
    //     cout << "Loop -----------------------------------" << target_count << endl;
    //     bool found = false;
    //     for (auto & ticket : tickets) {
    //         cout << "next ticket..." << endl;
    //         if (found) break;
    //         for (int i = 0; i < ticket.size() && !found; ++i) {
    //             auto field = ticket[i];
    //             cout << "  ticket field " << i << " possibilities: " << field.second.size() << endl;
    //             if (field.second.size() == target_count) { // potential candidate found
    //                 cout << "    candidates: ";
    //                 for (int candidate : field.second) {
    //                     bool can_map = true;
    //                     for (int m : mapping) {
    //                         if (candidate / 2 == m) {
    //                             can_map = false;
    //                         }
    //                     }
    //                     cout << candidate << " ";
    //                     if (mapping[i] == -1 && can_map) {
    //                         cout << endl << "      found at " << i;
    //                         mapping[i] = candidate / 2;
    //                         found = true;
    //                         break;
    //                     }
    //                 }
    //                 cout << endl;
    //             }
    //         }
    //     }
    //     if (!found) {
    //         ++target_count;
    //     }
    // }

    for (int i = 0; i < mapping.size(); ++i) {
        cout << i << " --> " << mapping[i] << endl;
    }

    unsigned __int128 result = 1;
    unsigned __int128 mod = 10;
    for (int i = 0; i < 6; ++i) {
        cout << my_ticket[mapping[i]].first << " * ";
        result *= (unsigned __int128) my_ticket[mapping[i]].first;
    }
    cout << " = ";
    while (result > 0) {
        cout << (int)(result % mod);
        result /= mod;
    } 
    cout << endl;
}
