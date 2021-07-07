#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> M; // Memory
string EMPTY_MEMVAL;

uint64_t binaryStringToUint(string bin_value)
{
    reverse(bin_value.begin(), bin_value.end());
    uint64_t value = 0;
    for (int i = 0; i < bin_value.length(); ++i) {
        if (bin_value[i] == '1') {
            value += (((uint64_t) 1) << i);
        }
    }
    return value;
}

void setMemory(string memloc, string memval, string mask)
{
    for (int i = 0; i < mask.length(); ++i) {
        if (mask[i] == '0') memval[i] = '0';
        if (mask[i] == '1') memval[i] = '1';
    }

    M[memloc] = memval;

    if (M[memloc] == EMPTY_MEMVAL) {
        M.erase(memloc);
    }
}

int main() 
{
    // grab input file
    ifstream infile ("../advent-of-code-2020/input/14.txt");
    if (!infile.is_open()) {
        return -1;
    }

    string mask = "";
    string memloc = "";
    string memval = "";

    for (int i = 0; i < 36; ++i) {
        EMPTY_MEMVAL += "0";
    }

    string line = "";
    while (getline(infile, line)) {
        cout << line << endl;
        if (line.substr(0, 4) == "mask") {
            mask = line.substr(7);
        } else {
            memloc = line.substr(4, line.find("]") - line.find("[") - 1);
            memval = line.substr(line.find("=") + 2);
            memval = bitset<36>(stoull(memval)).to_string();
            setMemory(memloc, memval, mask);
        }
    }

    uint64_t result = 0;
    for (auto entry : M) {
        result += binaryStringToUint(entry.second);

    }
    
    cout << result << endl;
}
