#include <bits/stdc++.h>

using namespace std;
#define loop(i, n) for (int i = 0; i < n; i++)
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int V;
    while (cin >> V) {
        if (V == 0) break;
        int E;
        cin >> E;
        vvi adj(V);
        vi visited(V);
        vector<bool> color(V);

        int s, t;
        loop(i, E) {
            cin >> s >> t;
            adj[s].push_back(t);
            adj[t].push_back(s);
        }

        queue<int> Q;
        Q.push(0);
        visited[0] = true;
        color[0] = 1; // white

        bool colorable = true;
        while (!Q.empty()) {
            int s = Q.front(); Q.pop();
            for (int t : adj[s]) {
                if (!visited[t]) {
                    visited[t] = true;
                    color[t] = !color[s];
                    Q.push(t);
                } else {
                    if (color[t] == color[s]) {
                        colorable = false;
                    }
                }
            }
            if (!colorable) break;
        }
        if (colorable) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }
    return 0;
}