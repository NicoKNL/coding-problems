#include <bits/stdc++.h>
using namespace std;

list<int> p1;
list<int> p2;

int main() 
{
    // grab input file
    ifstream infile ("../advent-of-code-2020/input/22.txt");
    if (!infile.is_open()) {
        return -1;
    }

    string line = "";
    bool player_1;
    while (getline(infile, line)) {
        if (line == "") continue;
        if (line.find("Player 1") != string::npos) {
            player_1 = true;
        } else if (line.find("Player 2") != string::npos) {
            player_1 = false;
        } else {
            if (player_1) {
                p1.push_back(stoi(line));
            } else {
                p2.push_back(stoi(line));
            }
        }
    }

    while (!p1.empty() && !p2.empty()) {
        int top1 = p1.front(); p1.pop_front();
        int top2 = p2.front(); p2.pop_front();
        if (top1 > top2) {
            p1.push_back(top1);
            p1.push_back(top2);
        } else {
            p2.push_back(top2);
            p2.push_back(top1);
        }
    }

    list<int> winner;
    if (p1.empty()) {
        winner = p2;
    } else {
        winner = p1;
    }

    long long result = 0;
    int i = 1;
    while (!winner.empty()) {
        result += i * winner.back();
        winner.pop_back();
        ++i;
    }
    cout << result << endl;
}
