#include <iostream>
#include <sstream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <locale>
#include <vector>

using namespace std;

string to_lowercase(string s) {
    char c;
    for (int i = 0; i < s.length(); i++) {
        c = s.at(i);
        if (c >= 'A' && c <= 'Z') s.replace(i, 1, 1, c + 32);
    }
    return s;
}

int main() {
    string line, word, sorted_word;
    istringstream ss_in;
    unordered_map<string, vector<string>> umap;
    bool eof = false;
    while (!eof) {
        getline(cin, line);
        ss_in.clear();
        ss_in.str(line);
        while (ss_in >> word) {
            if (word == "#") {
                eof = true;
                break;
            }
            sorted_word = to_lowercase(word);
            sort(sorted_word.begin(), sorted_word.end());
            if (umap.find(sorted_word) == umap.end()) {
                umap.insert({sorted_word, vector<string>{word}});
            } else {
                umap.at(sorted_word).push_back(word);
            }
        }
    }

    vector<string> ananagrams; /* sic */
    for (auto it: umap) {
        if (it.second.size() == 1) ananagrams.push_back(it.second.at(0));
    }

    sort(ananagrams.begin(), ananagrams.end());
    for (string sa: ananagrams) {
        cout << sa << endl;
    }
    return 0;
}