#include <bits/stdc++.h>
using namespace std;

list<int> player1;
list<int> player2;

int game = 0;

list<int> getCopyUpTo(list<int> l, int index)
{
    list<int> result;
    while (index--) {
        result.push_back(l.front());
        l.pop_front();
    } 
    return result;
}

__uint128_t hashDeck(list<int> & p1, list<int> & p2)
{
    __uint128_t h = 0;
    for (int & i : p1) {
        h += ((__uint128_t) 1 << (__uint128_t)(i - 1));
    }

    for (int & i : p2) {
        h += ((__uint128_t) 1 << (__uint128_t)(i - 1 + 64));
    }
    return h;
}

bool play(list<int> & p1, list<int> & p2) // true => p1 wins
{
    ++game;
    set<__uint128_t> hashes;
    int round = 1;

    while (!p1.empty() && !p2.empty()) {
        __uint128_t current_hash = hashDeck(p1, p2);

        if (hashes.find(current_hash) != hashes.end()) {
            int top1 = p1.front(); p1.pop_front();
            int top2 = p2.front(); p2.pop_front();

            p1.push_back(top1);
            p1.push_back(top2);
            continue;
        } else {
            hashes.insert(current_hash);
        }

        int top1 = p1.front(); p1.pop_front();
        int top2 = p2.front(); p2.pop_front();
        bool winner;

        if (top1 <= p1.size() && top2 <= p2.size()) {
            list<int> sub1 = getCopyUpTo(p1, top1);
            list<int> sub2 = getCopyUpTo(p2, top2);

            winner = play(sub1, sub2);
        } else {
            if (top1 > top2) {
                winner = true;
            } else {
                winner = false;
            }
        }

        if (winner) {
            p1.push_back(top1);
            p1.push_back(top2);
        } else {
            p2.push_back(top2);
            p2.push_back(top1);
        }

        ++round;
    }
    
    --game;
    if (p1.empty()) {
        return false; // p2 wins
    } else {
        return true; // p1 wins
    }
}

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
                player1.push_back(stoi(line));
            } else {
                player2.push_back(stoi(line));
            }
        }
    }

    play(player1, player2);
    list<int> winner;

    if (player1.empty()) {
        winner = player2;
    } else {
        winner = player1;
    }

    long long result = 0;
    long long i = 1;
    while (!winner.empty()) {
        result += i * (long long) winner.back();
        winner.pop_back();
        ++i;
    }

    cout << result << endl;
}
