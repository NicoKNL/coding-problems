#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
char suits[4] = {'S', 'H', 'D', 'C'};
char trackSuit[3] = {'K', 'Q', 'J'};
int find(unordered_map<char, int> umap, char token) {
    if (umap.find(token) == umap.end()) {
        return 0;
    } else {
        return umap[token];
    }
}

int main() {
    string s, card;
    while (getline(cin, s)) {
        istringstream ss_in;
        ss_in.str(s);

        unordered_map<char, int> umap;
        vector<char> kingsuits;
        vector<char> queensuits;
        vector<char> jacksuits;
        char type, suit;
        while (ss_in >> card) {
            type = card.at(0);
            suit = card.at(1);

            if (umap.find(type) == umap.end()) {
                umap[type] = 1;
            } else {
                umap[type] += 1;
            }

            if (umap.find(suit) == umap.end()) {
                umap[suit] = 1;
            } else {
                umap[suit] += 1;
            }

            if (type == 'K') kingsuits.push_back(suit);
            if (type == 'Q') queensuits.push_back(suit);
            if (type == 'J') jacksuits.push_back(suit);
        }

        int points = 0;
        int points567 = 0;
        // 1
        points += find(umap, 'A') * 4;
        points += find(umap, 'K') * 3;
        points += find(umap, 'Q') * 2;
        points += find(umap, 'J') * 1;

        // 2
        for (char s: kingsuits) {
            points -= find(umap, s) < 2 ? 1 : 0;
        }

        // 3
        for (char s: queensuits) {
            points -= find(umap, s) < 3 ? 1 : 0;
        }

        // 4
        for (char s: jacksuits) {
            points -= find(umap, s) < 4 ? 1 : 0;
        }

        for (char s: suits) {
            points567 += find(umap, s) == 2 ? 1 : 0; // 5
            points567 += find(umap, s) == 1 ? 2 : 0; // 6
            points567 += find(umap, s) == 0 ? 2 : 0; // 7

        }


        if (points < 14) {
            cout << "PASS" << endl;
        }

    }
    return 0;
}