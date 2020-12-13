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
        map<char, int> m;
        for (char c : line) {
            if ('A' <= c && c <= 'z') m[c]++;
        }

        int best = -1;
        string best_str;
        for (auto entry : m) {
            if (entry.second > best) {
                best = entry.second;
                best_str = entry.first;
            } else if (entry.second == best) {
                best_str += entry.first;
            }
        }
        cout << best_str << " " << best << endl;
    }
    return 0;
}