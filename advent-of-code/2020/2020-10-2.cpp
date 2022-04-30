#include <bits/stdc++.h>
using namespace std;

vector<int> adapters;

bool valid(const vector<int> & seq, unsigned int mask)
{
    // Extend mask with 1[...]1
    mask = mask << 1;
    mask += 1;
    mask += (1 << (seq.size() - 1));

    int prev = seq[0];
    for (int i = 1; i < seq.size(); ++i) {
        if (mask & (1 << i)) {
            if (seq[i] - prev > 3) return false;
            else prev = seq[i];
        } 
    }
    return true;
}

int countWays(int n) 
{

    vector<int> seq = {0};
    for (int i = 1; i <= n; ++i) {
        seq.push_back(i);
    }
    seq.push_back(seq[seq.size() - 1] + 3);
    unsigned int mask = 0;
    int count = 0;
    while (mask <= pow(2, n) - 1) {
        if (valid(seq, mask)) ++count;
        mask += 1;
    }
    return count;
}

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
    vector<int> absolute_diffs;

    for (int i = 1; i < adapters.size(); ++i) {
        ++diffs[adapters[i] - adapters[i - 1]];
        absolute_diffs.push_back(adapters[i] - adapters[i - 1]);
    }

    vector<int> sequences;

    int length = 0;
    for (int i = 0; i < absolute_diffs.size(); ++i) {
        if (absolute_diffs[i] == 1) ++length;
        if (absolute_diffs[i] == 3 && length > 0) {
            sequences.push_back(length);
            length = 0;
        }
    }

    long long ways = 1;
    for (int seq : sequences) {
        ways *= (long long) countWays(seq);
    }
    cout << ways << endl;
}
