#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

struct Vertex {
    int index = -1;
    int lowlink = -1;
    vector<int> adj;
    int comp = -1; // To check if on stack
};

vector<Vertex> V;
stack<int> STK;
int id = 0;
int comp = 0;

void Tarjan(int v) {
    V[v].index = id++;
    V[v].lowlink = V[v].index;

    // Set the depth index for v
    STK.push(v);
    for (int i = 0; i < V[v].adj.size(); i++) {
        int t_id = V[v].adj[i];
        if (V[t_id].index == -1) {
            Tarjan(t_id);
            V[v].lowlink = min(V[v].lowlink, V[t_id].lowlink);
        } else if (V[t_id].comp == -1) {
            V[v].lowlink = min(V[v].lowlink, V[t_id].index);
        }
    }
    if (V[v].lowlink == V[v].index) { // SCC found, v = root
        cout << "SSC: ";
        int j;
        do {
            j = STK.top(); STK.pop();
            cout << j << " ";
            V[j].comp = comp;
        } while (j != v);
        comp++;
        cout << endl;
    }
}

int main() {
    Vertex v0, v1, v2, v3, v4, v5, v6, v7, v8;
//    v0.adj.emplace_back(1);

    v1.adj.emplace_back(2);
    v1.adj.emplace_back(0);

    v2.adj.emplace_back(5);
    v2.adj.emplace_back(6);
    v2.adj.emplace_back(3);

    v3.adj.emplace_back(7);
    v3.adj.emplace_back(4);

    v4.adj.emplace_back(3);
    v4.adj.emplace_back(8);

    v5.adj.emplace_back(1);
    v5.adj.emplace_back(6);

    v6.adj.emplace_back(7);

    v7.adj.emplace_back(6);

    v8.adj.emplace_back(4);
    v8.adj.emplace_back(7);

    V.push_back(v0);
    V.push_back(v1);
    V.push_back(v2);
    V.push_back(v3);
    V.push_back(v4);
    V.push_back(v5);
    V.push_back(v6);
    V.push_back(v7);
    V.push_back(v8);

    for (int i = 0; i < V.size(); i++) {
        if (V[i].index == -1) Tarjan(i);
    }
    return 0;
}