#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi dfs_num, dfs_low, visited;
vi comp;
vvi components;
vvi adj;
stack<int> STK;
int dfsNumberCounter;

void Tarjan(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    STK.push(u);
    visited[u] = 1;
    for (int v : adj[u]) {
        if (dfs_num[v] == -1) { // unvisited
            Tarjan(v);
        }
        if (visited[v] == 1) {
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
    }

    if (dfs_low[u] == dfs_num[u]) { // SSC root
//        printf("SCC %d:", ++numSCC);
        comp = vi();
        while (true) {
            int v = STK.top(); STK.pop();
            visited[v] = -1;
            comp.push_back(v);
//            printf(" %d", v);
            if (u == v) break;
        }
//        printf("\n");
        components.push_back(comp);
    }
}

int main() {
    int cases = 1;
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        if (cases > 1) cout << endl;

        int k = 0;

        dfs_num.assign(n, -1);
        dfs_low.assign(n, 0);
        visited.assign(n, -1);
        adj.assign(n, vi());
        dfsNumberCounter = 0;
        STK = stack<int>();

        map<string, int> vmap;
        map<int, string> inv_vmap;
        loop(i, m) {
            string s, t;
            cin >> s >> t;
            if (vmap.find(s) == vmap.end()) {
                vmap[s] = k;
                inv_vmap[k] = s;
                k++;
            }
            if (vmap.find(t) == vmap.end()) {
                vmap[t] = k;
                inv_vmap[k] = t;
                k++;
            }
            adj[vmap[s]].push_back(vmap[t]);
        }

        components = vvi();
        for (int u = 0; u < n; u++) {
            if (dfs_num[u] == -1) {
                Tarjan(u);
            }
        }

        printf("Calling circles for data set %d:\n", cases);
        if (m == 0) {
            cases++;
            continue;
        }
        loop(i, components.size()) {
            loop(j, components[i].size()) {
                if (j > 0) cout << ", ";
                cout << inv_vmap[components[i][j]];
            }
            cout << endl;
        }
        cases++;

    }


    return 0;
}