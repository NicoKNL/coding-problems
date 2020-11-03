#include <bits/stdc++.h>
using namespace std;

int main()
{
    // grab input file
    ifstream infile("../projecteuler/input/p022_names.txt");
    if (!infile.is_open()) {
        return -1;
    }

    vector<string> names;
    string name;
    while (getline(infile, name, ',')) {
        name = name.substr(1, name.length() - 2);
        names.push_back(name);
    }

    sort(names.begin(), names.end());
    unsigned long long result = 0;
    int i = 1;
    for (string name : names) {
        unsigned long long namescore = 0;
        for (char c : name) {
            namescore += c - 64;
        }
        result += namescore * i;
        ++i;
    }
    cout << result;
}
