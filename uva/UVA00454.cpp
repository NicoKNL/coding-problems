#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

void run() {
    string s, s_sorted;
    unordered_map<string, vector<string>> umap;
    vector<string> anagrams;
    while (getline(cin, s) && !s.empty()) {
        s_sorted = s;
        s_sorted.erase(remove(s_sorted.begin(), s_sorted.end(), ' '), s_sorted.end());
        sort(s_sorted.begin(), s_sorted.end());
        if (umap.find(s_sorted) == umap.end()) {
            umap[s_sorted] = vector<string> {s};
        } else {
            umap[s_sorted].push_back(s);
        }
    }

    vector<string> matches;
    string a, b;
    for (auto it: umap) {
        matches = it.second;
        if (matches.size() > 1) {
            sort(matches.begin(), matches.end());

            for (int i = 0; i < matches.size(); i++) {
                for (int j = i + 1; j < matches.size(); j++) {
                    a = matches.at(i);
                    b = matches.at(j);
                    anagrams.push_back(a.append(" = ").append(b));
                }
            }
        }
    }

    sort(anagrams.begin(), anagrams.end());
    for (string s: anagrams) {
        cout << s << endl;
    }
}

int main() {
    int n;
    string s;
    cin >> n;
    getline(cin, s); // consume \n
    getline(cin, s); // consume \n
    while (n--) {
        run();
        if (n) cout << endl;
    }
    return 0;
}