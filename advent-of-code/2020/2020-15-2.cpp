#include <bits/stdc++.h>
using namespace std;

// int main() 
// {
//     unordered_map<int, vector<int>> M = {
//         {20, {1}},
//         {9, {2}},
//         {11, {3}},
//         {0, {4}},
//         {1, {5}},
//         {2, {6}}  
//     };

//     int turn = 7;
//     int prev_n = 2;
//     while (turn <= 30000000) {
//         int next_n;
//         vector<int> prev_turns = M[prev_n];
//         int count = prev_turns.size();
//         if (count == 1) {
//             next_n = 0;
//         } else {
//             next_n = prev_turns[count - 1] - prev_turns[count - 2];
//         }

//         if (M.find(next_n) != M.end()) {
//             if (M[next_n].size() < 2) {
//                 M[next_n].push_back(turn);
//             } else {
//                 M[next_n][0] = turn;
//                 swap(M[next_n][0], M[next_n][1]);
//             }
//         } else {
//             M[next_n] = {turn};
//         }
//         prev_n = next_n;
//         ++turn;
//     }
//     cout << prev_n << endl;
// }

int main() 
{
    vector<int> M(30000001, 0);
    vector<vector<int>> C(30000001);
    M[20] = 1;
    C[20] = {1};
    M[9] = 2;
    C[9] = {2};
    M[11] = 3;
    C[11] = {3};
    M[0] = 4;
    C[0] = {4};
    M[1] = 5;
    C[1] = {5};
    M[2] = 6;
    C[2] = {6};

    int turn = 7;
    int prev_n = 2;
    while (turn <= 30000000) {
        int next_n;
        int count = C[prev_n].size();
        if (count == 1) {
            next_n = 0;
        } else {
            next_n = C[prev_n][count - 1] - C[prev_n][count - 2];
        }

        if (C[next_n].size() < 2) {
            C[next_n].emplace_back(turn);
        } else {
            C[next_n][0] = turn;
            swap(C[next_n][0], C[next_n][1]);
        }
        prev_n = next_n;
        ++turn;
    }
    cout << prev_n << endl;
}
