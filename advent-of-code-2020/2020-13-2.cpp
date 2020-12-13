#include <bits/stdc++.h>
using namespace std;

int main() 
{
    // grab input file
    ifstream infile ("../advent-of-code-2020/input/13.txt");
    if (!infile.is_open()) {
        return -1;
    }

    string line = "";
    long long depart = 0;
    vector<long long> busses;
    long long max_bus = -1;
    long long max_bus_id = -1;
    int i = 0;
    while (getline(infile, line)) {
        if (depart == 0) {
            depart = stoll(line);
        } else {
            stringstream ss(line);
            string data = "";
            while (getline(ss, data, ',')) {
                if (data == "x") {
                    busses.push_back(-1);
                } else {
                    busses.push_back(stoll(data));
                }
                if (busses[busses.size() - 1] > max_bus) {
                    max_bus = busses[busses.size() - 1];
                    max_bus_id = i;
                }
                ++i;
            }
        }
    }

    depart = 0; //max_bus_id;
    long long j = 0;
    while (true) {
        depart += max_bus;
        // cout << "Depart: " << depart << endl;
        bool valid = true;
        for (int i = 0; i < busses.size(); ++i) {
            if (busses[i] == -1) {
                continue;
            } else {
                // cout << depart + (i - max_bus_id) << ", ";
                if ((depart + (i - max_bus_id)) % busses[i] != 0) {
                    valid = false;
                    break;
                }
            }
        }
        // cout << endl;
        if (valid) break;
        ++j;
        if (j % 10000000 == 0) {
            cout << "Depart: " << depart << endl;
        }
    }
    cout << depart - max_bus_id << endl;
}
