#include <bits/stdc++.h>
using namespace std;

typedef uint64_t bigint;

int main() 
{
    // grab input file
    ifstream infile ("../advent-of-code-2020/input/13.txt");
    if (!infile.is_open()) {
        return -1;
    }

    // Input parsing
    string line = "";
    bigint depart = 0;
    vector<pair<bigint, bigint>> busses;
    bigint i = 0;
    while (getline(infile, line)) {
        if (depart == 0) {
            depart = stoll(line);
        } else {
            stringstream ss(line);
            string data = "";

            while (getline(ss, data, ',')) {
                if (data != "x") {
                    bigint a = stoull(data);

                    bigint b = stoull(data);
                    while (a < i) {
                        a += b;
                    }
                    a = (a - i) % a;
                    busses.push_back({a, b}); // Constructs the appropriate `a mod b` from the input
                    cout << "i: " << i << " :: " << busses[busses.size() - 1].first << " mod " << busses[busses.size() - 1].second << endl; // Prints the `a mod b`
                }
                ++i;
            }
        }
    }

    // Sort from large to small to improve sieve speed
    sort(busses.begin(), busses.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });

    // Sieve
    bigint t = busses[0].first;
    bigint M = busses[0].second;   
    for (bigint i = 0; i < busses.size() - 1; ++i) {
        bigint a2 = busses[i + 1].first;
        bigint n2 = busses[i + 1].second;
        bigint tmp = t;
        bigint j = 1;
        while (tmp % n2 != a2) {
            tmp = t + (j * M);
            ++j;
        }
        t = tmp;
        M *= n2;
    }

    cout << t << endl;
}
