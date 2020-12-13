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
    uint64_t depart = 0;
    vector<pair<uint64_t, uint64_t>> busses;
    uint64_t max_bus = -1;
    uint64_t max_bus_id = -1;
    uint64_t i = 0;
    while (getline(infile, line)) {
        if (depart == 0) {
            depart = stoll(line);
        } else {
            stringstream ss(line);
            string data = "";
            while (getline(ss, data, ',')) {
                if (data == "x") {
                    // busses.push_back(-1);
                } else {
                    busses.push_back({i, stoll(data)});
                }
                ++i;
            }
        }
    }

    // Example
    // t === 0 mod 7
    // t === 12 mod 13
    // t + 2
    // t + 3
    // t === 55 mod 59
    // t + 5
    // t === 25 mod 31
    // t === 12 mod 19
    //
    // t === (13*59*31*19)(7) * (7*59*31*19)(13) * (7*13*31*19)(59) * (7*13*59*19)(31) * (7*13*59*31)(19) 
    // t === (4)(7) * (11)(13) * (27)(59) * (21)(31) * (18)(19)
    uint64_t modab = 1;
    for (auto bus : busses) {
        modab *= bus.second;
    }

    // cout << "modab: " << modab << endl;

    uint64_t result = 0;
    for (int i = 0; i < busses.size(); ++i) {
        cout << "--------------" << endl;
        cout << "Calculating: " << (long long) busses[i].second << endl;
        uint64_t p = busses[i].second;
        uint64_t a = (p - busses[i].first) % p;
        cout << (long long) a << " mod " << (long long) p << endl;
        uint64_t b = 1;
        for (int j = 0; j < busses.size(); ++j) {
            if (i != j) {
                b *= busses[j].second;
            }
        }
        uint64_t tmp = b;
        // cout << "b: " << (long long) b << endl;
        while (tmp % p != a) {
            tmp += b;
            // cout << "tmp: " << (long long) tmp << endl;
        }
        // tmp %= modab;
        result += tmp;
        result %= modab;
    }
    long long res = result % modab;
    cout << (long long) modab << endl;
    cout << res << endl;

}
