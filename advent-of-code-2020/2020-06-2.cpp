#include <bits/stdc++.h>
using namespace std;

int main() {
    // grab input file
    ifstream infile("../advent-of-code-2020/input/06.txt");
    if (!infile.is_open()) {
        return -1;
    }

    int sum = 0;

    int max_count = 0;
    int group_size = 0;
    unordered_map<char, int> answers;
    string line = "";
    while (getline(infile, line)) {
        if (line == "") {
            for (auto entry : answers) {
                if (entry.second == group_size && group_size != 0) {
                    sum += 1;
                }
            }
            answers = {};
            max_count = 0;
            group_size = 0;
        }
        string person;
        stringstream ss(line);
        while (getline(ss, person)) {
            ++group_size;
            for (char c: person) {
                answers[c] += 1;
            }
        }
    }

    for (auto entry : answers) {
        cout << group_size << ", " << entry.second << endl;
        if (entry.second == group_size && group_size != 0) {
            sum += 1;
        }
    }
    printf("%d", sum);
    
}
