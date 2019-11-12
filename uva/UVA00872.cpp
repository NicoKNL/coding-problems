#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vi visited;
vector<vector<char>> adj;
vector<vector<char>> solutions;
vector<char> verts;
void backtrack(int i, int j, vector<char> & sol) {
    if (i == j) {
        solutions.push_back(sol);
    } else {
        for (char c : verts) {
            if (!visited[c]) {
                bool possible = true;
                for (char d : adj[c]) {
                    if (!visited[d]) possible = false;
                }
                if (possible) {
                    visited[c] = 1;
                    sol[i] = c;
                    backtrack(i + 1, j, sol);
                    visited[c] = 0;
                }
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    string s;
    getline(cin, s); // \n

    for (int cases = 0; cases < n; cases++) {
        getline(cin, s);  // blank line
        getline(cin, s);
        stringstream nodes(s);

        getline(cin, s);
        stringstream edges(s);

        visited.assign(500, 0);
        adj.assign(500, vector<char>());
        verts = vector<char>();
        solutions = vector<vector<char>>();
        char v;
        while (nodes >> v) {
            verts.push_back(v);
        }
        sort(verts.begin(), verts.end());

        while (edges >> s) {
            adj[s[2]].push_back(s[0]);
        }

        vector<char> sol = vector<char>(verts.size());
        backtrack(0, verts.size(), sol);

        if (solutions.size() == 0) {
            cout << "NO" << endl;
        } else {
            for (vector<char> solution : solutions) {
                for (int i = 0; i < solution.size(); i++) {
                    if (i > 0) cout << " ";
                    cout << solution[i];
                }
                cout << endl;
            }
        }
        if (cases < n - 1) cout << endl;
    }
    return 0;
}