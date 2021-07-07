#include <bits/stdc++.h>
using namespace std;

int main() 
{
    unordered_map<int, vector<int>> M = {
        {20, {1}},
        {9, {2}},
        {11, {3}},
        {0, {4}},
        {1, {5}},
        {2, {6}}  
    };

    int turn = 7;
    int prev_n = 2;
    while (turn <= 2020) {
        int next_n;
        vector<int> prev_turns = M[prev_n];
        int count = prev_turns.size();
        if (count == 1) {
            next_n = 0;
        } else {
            next_n = prev_turns[count - 1] - prev_turns[count - 2];
        }

        if (M.find(next_n) != M.end()) {
            M[next_n].push_back(turn);
        } else {
            M[next_n] = {turn};
        }
        prev_n = next_n;
        ++turn;
    }
    cout << prev_n << endl;
}
