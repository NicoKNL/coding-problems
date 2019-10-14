#include <bits/stdc++.h>

using namespace std;
int shortest_path_length;
int counter;
struct Vertex{
    int id;
    int dist;
    int parent = -1;
    bool visited = false;
//    vector<int> adj; /* unweighted */
    vector<pair<int, int>> adj;    /* weighted */
};

void dfs(vector<Vertex> & V, int id, int target, int length) {
    if (id == target) {
        if (length <= shortest_path_length + 1) {
            counter++;
        }
        return;
    }

    if (length > shortest_path_length + 1) {
        return;
    }

    for (int i = 0; i < V[id].adj.size(); i++) {
        int t_id = V[id].adj[i].first;
        int t_dist = V[id].adj[i].second;
        if (!V[t_id].visited) {
            V[t_id].visited = true;
            dfs(V, t_id, target, length + t_dist);
            V[t_id].visited = false;
        }
    }
}


int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        counter = 0;
        int v, e;
        cin >> v >> e;
        vector<Vertex> V(v + 1);

        int source, target, weight;
        for (int i = 0; i < e; i++) {
            cin >> source >> target >> weight;
            V[source].adj.emplace_back(make_pair(target, weight));
        }

        cin >> source >> target;

        // Updates to vertdata
        for (int i = 0; i < v + 1; i++) {
            V[i].id = i;
            if (i == source) {
                V[i].dist = 0;
            } else {
                V[i].dist = INT_MAX;
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
        PQ.push(make_pair(0, source));
        while (!PQ.empty()) {
            int id = PQ.top().second;
            int dist = PQ.top().first;
            PQ.pop();
            for (int i = 0; i < V[id].adj.size(); i++) {
                int t_id = V[id].adj[i].first;
                int t_dist = V[id].adj[i].second;
                if (dist + t_dist < V[t_id].dist) {
                    V[t_id].dist = dist + t_dist;
                    PQ.push(make_pair(V[t_id].dist, t_id));
                    V[t_id].parent = id;
                }
            }
        }

        shortest_path_length = V[target].dist;
        V[source].visited = true;
        dfs(V, source, target, 0);
        cout << counter << endl;

    }
    return 0;
}

/*
2
5 8
1 2 3
1 3 2
1 4 5
2 3 1
2 5 3
3 4 2
3 5 4
4 5 3
1 5
5 6
2 3 1
3 2 1
3 1 10
4 5 2
5 2 7
5 2 7
4 1


*/