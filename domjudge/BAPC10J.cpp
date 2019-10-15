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
            if (V[t_id].parent == -1 && )
        }
    }
}

int maxflow() {
    while (searching()) {
        int k = sink;
    }
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
    vector<vector<int>> capacity(h+v+2)(h+v+2);
    vector<vector<int>> flow(h+v+2)(h+v+2);
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
        capacity[i][sink] = 1; // h-word to sink
    }

    // read in vertical words
    for (int i = h; i < h + v; i++) {
        cin >> V[i].x;
        cin >> V[i].y;
        cin >> V[i].word;
        capacity[source][i] = 1; // source to v-word
    }

    // set up bipartite edges. Going from vertical words to horizontal words, capacity = 1;
    for (int i = v; i < h+v; i++) {
        int min_y = V[i].y;
        int max_y = V[i].y + V[i].word.length() - 1;

        for (int j = 0; j < h; j++) {
            int min_x = V[j].x;
            int max_x = V[j].x + V[j].word.size();

            // Check if the words cross with each other
            if (!(min_y <= V[j].y && V[j].y <= max_y && min_x <= V[i].x && V[i].x <= max_x)) continue;

            for (int j = 0; j < V[i].word.size(); j++) {
                if (V[i].word.at(i) != V[j].word.at(V[i].x)) {
                    V[i].adj.push_back(j);
                    V[j].adj.push_back(i);
                    capacity[i][j] = 1;
                }
            }
        }
    }
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
 */