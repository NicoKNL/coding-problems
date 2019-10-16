#include<bits/stdc++.h>

using namespace std;

struct Vertex {
    int x = -1;
    int y = -1;
    string word;
    vector<int> adj;
    int parent;
};

bool search(vector<Vertex> & V, vector<vector<int>> & capacity, vector<vector<int>> & flow, int source, int sink) {
    for (int i = 0; i < V.size(); i++) {
        V[i].parent = -1;
    }
    stack<int> STK;
    STK.push(source);
    V[source].parent = -2;
    while (!STK.empty()) {
        int id = STK.top(); STK.pop();
        for (int i = 0; i < V[id].adj.size(); i++) {
            int t_id = V[id].adj[i];
//            cout << t_id << ", " << id << "-----" << flow[id][t_id] << " " << capacity[id][t_id] << " parent: " << V[t_id].parent << endl;
            if (V[t_id].parent == -1 && flow[id][t_id] < capacity[id][t_id]) {
                V[t_id].parent = id;
                if (t_id == sink) return true;
                STK.push(t_id);
            }
        }
    }
    return false;
}

int maxflow(vector<Vertex> & V, vector<vector<int>> & capacity, vector<vector<int>> & flow, int source, int sink) {
    while (search(V, capacity, flow, source, sink)) {
        int id = sink;  // target
        int t_id = V[id].parent; // source
        int m = capacity[t_id][id] - flow[t_id][id];
        while (t_id != -2) {
            m = min(m, capacity[t_id][id] - flow[t_id][id]);
            id = t_id;
            t_id = V[id].parent;
        }

        id = sink;
        t_id = V[id].parent;
        while (t_id != -2) {
            flow[t_id][id] += m;
            flow[id][t_id] -= m;
            id = t_id;
            t_id = V[id].parent;
        }
    }
    int sum = 0;
    for (int i = 0; i < V.size(); i++) {
        sum += flow[source][i];
    }
    return sum;
}

void oneRun()
{
    int h, v; // Number of horizontal, and vertical words
    cin >> h >> v;
    vector<Vertex> V(h+v+2); // h horizontal followed by v vertical
    int source = h + v, sink = h + v + 1;

    /*
     * General construction:
     *         SOURCE -1- V-WORD -1- H-WORD -1- SINK
     */

    // set up capacity/flow matrices
    vector<vector<int>> capacity(h+v+2, vector<int>(h+v+2, 0));
    vector<vector<int>> flow(h+v+2, vector<int>(h+v+2, 0));
    for (int i = 0; i < h+v; i++) {
        for (int j = 0; j < h+v; j++) {
            capacity[i][j] = 0;
            flow[i][j] = 0;
        }
    }

    // read in horizontal words
    for (int i = 0; i < h; i++) {
        cin >> V[i].x;
        cin >> V[i].y;
        cin >> V[i].word;
        V[i].adj.emplace_back(sink);
        capacity[i][sink] = 1; // h-word to sink
    }

    // read in vertical words
    for (int i = h; i < h + v; i++) {
        cin >> V[i].x;
        cin >> V[i].y;
        cin >> V[i].word;
        V[source].adj.emplace_back(i);
        capacity[source][i] = 1; // source to v-word
    }

    // set up bipartite edges. Going from vertical words to horizontal words, capacity = 1;
    for (int i = v; i < h+v; i++) { // for verticals
        int min_y = V[i].y;
        int max_y = V[i].y + V[i].word.length() - 1;

        for (int j = 0; j < h; j++) { // for horizontals
            int min_x = V[j].x;
            int max_x = V[j].x + V[j].word.size();

            // Check if the words cross with each other
            if (!(min_y <= V[j].y && V[j].y <= max_y && min_x <= V[i].x && V[i].x <= max_x)) continue;

            if (V[i].word.at(V[j].y - V[i].y) != V[j].word.at(V[i].x - V[j].x)) {
//                cout << V[i].word << " - " << V[j].word << " " << V[i].word.at(V[j].y - V[i].y) << " and " << V[j].word.at(V[i].x - V[j].x) << endl;
                V[i].adj.push_back(j);
                V[j].adj.push_back(i);
                capacity[i][j] = 1;
            }
        }
    }
    int total_flow = maxflow(V, capacity, flow, source, sink);
    cout << h + v - total_flow << endl;
}

int main()
{
    int n_cases;
    cin >> n_cases;
    while (n_cases--) oneRun();
    return 0;
}

/** Test cases


1
2 2
0 1 BAPC
0 2 LEIDEN
0 0 SOLUTION
2 1 WINNER

output: 3


1
1 4
0 1 HELLO
1 0 HI
2 0 BYE
3 0 GOODBYE
4 0 FAREWELL

output: 4

5
2 2
0 1 BAPC
0 2 LEIDEN
0 0 SOLUTION
2 1 WINNER
1 4
0 1 HELLO
1 0 HI
2 0 BYE
3 0 GOODBYE
4 0 FAREWELL
2 2
10 11 BAPC
10 12 LEIDEN
10 10 SOLUTION
12 11 WINNER
2 0
0 1 BAPC
0 2 LEIDEN
0 2
0 0 SOLUTION
2 1 WINNER
 */