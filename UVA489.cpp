#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

string unique(string s) {
    unordered_map<char, bool> umap;
    string unique_chars;
    for (char c: s) {
        if (umap.find(c) == umap.end()) {
            umap[c] = true;
            unique_chars += c;
        }
    }
    return unique_chars;
}

int count(string s, char c1) {
    int count = 0;
    for (char c2: s) {
        if (c1 == c2) count++;
    }
    return count;
}

int main() {
    int n;
    string answer, guess;
    while (true) {
        cin >> n;
        if (n == -1) break;
        cin >> answer >> guess;
        answer = unique(answer);
        guess = unique(guess);

        int wrong = 0;
        int correct = 0;
        for (char c: guess) {
            if (answer.find(c) == string::npos) {
                wrong++;
                if (wrong >= 7) break;
            } else {
                correct++;
                if (correct == answer.size()) break;
            }
        }

        cout << "Round " << n << endl;
        if (wrong >= 7) {
            cout << "You lose." << endl;
        } else if (correct == answer.size()) {
            cout << "You win." << endl;
        } else {
            cout << "You chickened out." << endl;
        }
    }

    return 0;
}