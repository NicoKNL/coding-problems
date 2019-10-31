#include <bits/stdc++.h>

using namespace std;
struct frame {
    int first = 0, second = 0;
};

int main() {
    string in;
    while (getline(cin, in)) {
        if (in == "Game Over") break;
        stringstream ss(in);
        int score = 0;
        vector<frame> frames(12);

        char c;

        int round = 0;
        bool first = true;
        while (ss >> c) {
            if (c == '/') {
                frames[round].second = 10 - frames[round].first;
                first = true;
                round++;
            } else if (c == 'X') {
                frames[round].first = 10;
                round++;
            } else {
                if (first) {
                    frames[round].first = c - '0';
                    first = false;
                } else {
                    frames[round].second = c - '0';
                    round++;
                    first = true;
                }
            }
        }

        for (int i = 0; i < 10; i++) {
            score += frames[i].first;
            score += frames[i].second;
            if (frames[i].first == 10) {// strike
                score += frames[i+1].first;
                if (frames[i+1].first == 10) {
                    score += frames[i+2].first;
                } else {
                    score += frames[i+1].second;
                }
            } else if (frames[i].first + frames[i].second == 10) { // spare
                score += frames[i+1].first;
            }
        }
        cout << score << endl;
    }
    return 0;
}