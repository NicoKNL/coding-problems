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
    while (getline(infile, line)) {
        if (depart == 0) {
            depart = stoll(line);
        } else {
            stringstream ss(line);
            string data = "";
            while (getline(ss, data, ',')) {
                if (data == "x") continue;
                busses.push_back(stoll(data));
            }
        }
    }

    long long id;
    long long remainder = 9999999;
    for (auto bus : busses) {
        cout << "bus: " << bus << ", remainder: " << bus - (depart % bus) << endl;
        if (bus - (depart % bus) < remainder) {
            id = bus;
            remainder = bus - (depart % bus);
        }
    }
    cout << id * remainder << endl;

}
