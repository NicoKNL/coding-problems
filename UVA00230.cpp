#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    string title, author;
    vector<string> inventory;
    while (getline(cin, s)) {
        if (s == "END") break;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '\"') {
                title = s.substr(1, i - 1);
                author = s.substr(i + 5);
                break;
            }
        }
        inventory.push_back(author.append(" ").append(title));
    }

    sort(inventory.begin(), inventory.end());

    vector<string> borrowed;
    vector<string> returned;
    while (getline(cin, s)) {
        if (s == "END") break;
        if (s == "SHELVE") {
            /* shelving logic */
        } else {

        }
    }
    return 0;
}