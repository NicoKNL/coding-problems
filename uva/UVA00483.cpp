#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        string s;
        vector<string> words;
        while (ss >> s) {
            words.push_back(s);
        }
        
        for (int i = 0; i < words.size(); i++) {
            if (i > 0) cout << " ";
            reverse(words[i].begin(), words[i].end());
            cout << words[i];
        }
        cout << endl;
    }
    return 0;
}