#include <bits/stdc++.h>
using namespace std;

int main() {
    // grab input file
    ifstream infile("../advent-of-code-2020/input/06.txt");
    if (!infile.is_open()) {
        return -1;
    }

    int sum = 0;

    unordered_set<char> answers;
    string line = "";
    while (getline(infile, line)) {
        if (line == "") {
            sum += answers.size();
            answers = {};
        }
        string person;
        stringstream ss(line);
        while (getline(ss, person)) {
            for (char c: person) {
                answers.insert(c);
            }
        }
    }

    sum += answers.size();
    printf("%d", sum);
    
}
