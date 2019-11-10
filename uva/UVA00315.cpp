#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vi dfs_num;
vi dfs_low;
vi dfs_parent;
vi articulation_vertex;
vvii adj_list;
int V;
int dfsRoot;
int rootChildren;
int counter;

enum {UNVISITED = -333};

void articulationPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = counter++;
    for (auto edge : adj_list[u]) {
        int v = edge.first;
        if (dfs_num[v] == UNVISITED) {
            dfs_parent[v] = u;
            if (u == dfsRoot) rootChildren++;

            articulationPointAndBridge(v);

            if (dfs_low[v] >= dfs_num[u]) {
                articulation_vertex[u] = 1;
            }
//            if (dfs_low[v] > dfs_num[u]) {
//                printf(" Edge (%d, %d) is a bridge\n", u, v);
//            }

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if (v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main() {
    while (cin >> V) {
        if (V == 0) break;

        adj_list = vvii(V);

        string s;
        getline(cin, s); // consume \n
        while (getline(cin, s))  {
            stringstream ss(s);
            int source;
            ss >> source;
            if (source == 0) break;
            source--;
            int target;
            while(ss >> target) {
                target--;
                adj_list[source].push_back({target, 0});
                adj_list[target].push_back({source, 0});
            }
        }

        counter = 0;
        dfs_num = vi(V, UNVISITED); // -1 => unvisited
        dfs_low = vi(V, 0);
        dfs_parent = vi(V, -1);
        articulation_vertex = vi(V, 0);

        int artpoints = 0;
//        printf("Bridges: \n");
        for (int u = 0; u < V; u++) {
            if (dfs_num[u] == UNVISITED) {
                dfsRoot = u;
                rootChildren = 0;
                articulationPointAndBridge(u);
                articulation_vertex[dfsRoot] = (rootChildren > 1);
            }
        }
//            printf("Articulation Points:\n");
        for (int u = 0; u < V; u++) {
            if (articulation_vertex[u]) {
                artpoints++;
//                    printf(" Vertex %d\n", i);
            }
        }
        cout << artpoints << endl;
    }

    return 0;
}