#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, int> valueMap = {
        {'A', 10},
        {'K', 10},
        {'Q', 10},
        {'J', 10},
        {'T', 10}
};

int main() {
    int n;
    cin >> n;
    string s;
    char value, suit;

    while (n--) {
        vector<string> cardpile;
        vector<string> hand;
        for (int i = 0; i < 52; i++) {
            cin >> s;
            cardpile.push_back(s);
        }
//        value = s.at(0);
//        suit = s.at(1);
        int Y = 0;
        int X;
        string card;
        for (int i = 0; i < 3; i++) {
            // Take top 25 cards from pile in hand
            hand = vector<string>(cardpile.end() - 25, cardpile.end());
            cardpile = vector<string>(cardpile.begin(), cardpile.end() - 25);

            // Take top card card from pile
            card = cardpile[cardpile.size()-1];
            value = card.at(0);
            if (valueMap.find(value) == valueMap.end()) {
                X = value - '0';
            } else {
                X = valueMap[value]; // 10
            }
            Y += X;
            // Throw away
            cardpile = vector<string>(cardpile.begin(), cardpile.end() - (10 - X));

            // Put back cards from hand
            cardpile.insert(cardpile.end(), hand.begin(), hand.end());
        }

        cout << cardpile[Y - 1] << endl;
        cout << cardpile[Y] << endl;
        cout << cardpile[Y + 1] << endl;
    }
    return 0;
}

// TODO: finish

/*
 * 52
 * 25 -
 * ------
 * 27
 * 1 -
 * ------
 * 26
 * 8 -
 * ------
 * 18
 * 25 +
 * ----
 * 43
 * 25 -
 * ----
 * 18
 * 1 -
 * ----
 * 17
 * 8 -
 * ----
 * 9
 * 25 +
 * ----
 * 34
 * 25 -
 * ----
 * 9
 * 1 -
 * ----
 * 8
 * 8 -
 * ----
 * 0
 *
 */
