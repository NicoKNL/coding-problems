#include <bits/stdc++.h>
using namespace std;

vector<int> adapters;

int main() 
{
    // grab input file
    ifstream infile ("../advent-of-code-2020/input/10.txt");
    if (!infile.is_open()) {
        return -1;
    }

    string line = "";
    adapters.push_back(0);
    while (getline(infile, line)) {
        adapters.push_back(stoi(line));
    }

    sort(adapters.begin(), adapters.end());
    adapters.push_back(adapters[adapters.size() - 1] + 3);

    vector<int> diffs = {0, 0, 0, 0};

    for (int i = 1; i < adapters.size(); ++i) {
        ++diffs[adapters[i] - adapters[i - 1]];
        // cout << adapters[i] - adapters[i - 1] << endl;
    }

    cout << diffs[1] * diffs[3] << endl;
}
