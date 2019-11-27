#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void print(vector<string> & sol) {
    for (string s : sol) {
        cout << s;
    }
    cout << endl;
}

void recurse(string & rule, vector<string> & dict, int step, vector<string> sol) {
    if (step == rule.size()) {
        print(sol);
        return;
    }

    if (rule[step] == '0') {
        for (int i = 0; i < 10; i++) {
            sol[step] = to_string(i);
            recurse(rule, dict, step + 1, sol);
        }
    } else if (rule[step] == '#') {
        for (string w : dict) {
            sol[step] = w;
            recurse(rule, dict, step + 1, sol);
        }
    }
}

int main() {
    int n;
    while (cin >> n) {
        vector<string> dict(n);
        loop(i, n) cin >> dict[i];

        int m;
        cin >> m;
        vector<string> rules(m);
        loop(i, m) cin >> rules[i];

        printf("--\n");
        for (string rule : rules) {
            vector<string> sol(rule.size());
            recurse(rule, dict, 0, sol);
        }
    }
    return 0;
}