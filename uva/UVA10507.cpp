#include <bits/stdc++.h>

using namespace std;

int main() {
    int slept, connections;
    while (cin >> slept) {
        cin >> connections;
        map<char, int> m;
        vector<vector<int>> adj (slept, vector<int>());
        vector<bool> awake(slept);
        string init, conn;
        cin >> init;
        int i = 0;
        for (char c: init) {
            m[c] = i;
            awake[i] = true;
            i++;
        }

        for (int j = 0; j < connections; j++) {
            cin >> conn;
            for (char c : conn) {
                if (m.find(c) == m.end()) {
                    m[c] = i;
                    i++;
                }
            }
            int a = m[conn[0]];
            int b = m[conn[1]];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int years = 0;
        for (int k = 0; k < 26; k++) {
            vector<int> waking;
            for (int v = 0; v < slept; v++) {
                if (awake[v]) continue;
                int count = 0;
                for (int v_adj : adj[v]) {
                    if (awake[v_adj]) count++;

                }
                if (count >= 3) waking.push_back(v);
            }
            if (!waking.empty()) {
                for (int v : waking) awake[v] = true;
                years++;
            } else {
                break;
            }
        }

        bool all_awake = true;
        for (int v = 0; v < slept; v++) {
            if (!awake[v]) all_awake = false;
        }

        if (!all_awake) {
            cout << "THIS BRAIN NEVER WAKES UP" << endl;
        } else {
            cout << "WAKE UP IN, " << years << ", YEARS" << endl;
        }
    }

    return 0;
}

/*
6
11
HAB
AB
AC
AH
BD
BC
BF
CD
CF
CH
DF
FH
 */