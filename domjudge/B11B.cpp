#include <bits/stdc++.h>
using namespace std;

vector<int> four_neighbours(int row, int col, int rows, int cols) {
    vector<int> adj;
    int base = row * cols + col;
    if (row - 1 >= 0) adj.push_back(base - cols);
    if (row + 1 < rows) adj.push_back(base + cols);
    if (col - 1 >= 0) adj.push_back( base - 1);
    if (col + 1 < cols) adj.push_back(base + 1);
    return adj;
}

struct Edge {
    int target;
    int w; // weight
};

struct Node {
    int id;
    vector<Edge> adj;
    int dist;
    bool visited;
    char token;

    void addEdge(int n, int w) {
        Edge e;
        e.target = n;
        e.w = w;
        adj.push_back(e);
    }
};

bool operator>(const Node & a, const Node & b) {
    return a.dist > b.dist;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int rows, cols, delay;
        cin >> rows >> cols >> delay;
        vector<Node> V;
        string srow;
        vector<int> adj;
        int s = -1;
        vector<int> targets;
        int id = 0;
        int w;
        // Construct graph verts
        for (int row = 0; row < rows; row++) {
            cin >> srow;
            for (int col = 0; col < cols; col++) {
                Node v;
                v.id = id;
                v.token = srow.at(col);
//                adj = four_neighbours(row, col, rows, cols);

                if (v.token == 'S') {
                    s = V.size(); // The node we will push now will have this index
                    v.dist = 0;
                } else {
                    v.dist = INT_MAX;
                }

                V.push_back(v);
                id++;

                // track all targets ('.' on edge)
                if ((row == 0 || row == rows - 1 || col == 0 || col == cols - 1) && v.token != '#') targets.push_back(V.size() - 1);
            }
        }

        // Add relevant edges
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int index = row * cols + col;
                if (V[index].token == '#') continue;

                vector<int> adj = four_neighbours(row, col, rows, cols);
                for (int a : adj) {
                    if (V[a].token == '#') continue;

                    w = 1;
                    if (V[a].token == '@') {
                        w = delay + 1;
                    }
                    V[index].addEdge(a, w);
                }
            }
        }

        priority_queue<Node, vector<Node>, greater<Node>> pq;
        pq.push(V[s]);

        int current;
        while (!pq.empty()) {
            current = pq.top().id;
            pq.pop();
            for (auto const & e: V[current].adj) {
                if (V[e.target].dist > V[current].dist + e.w) { // todo; swap around
                    V[e.target].dist = V[current].dist + e.w;
                    pq.push(V[e.target]); // Re-add to queue
                }
            }
        }

        int best = INT_MAX;
        for (int t : targets) {
            if (V[t].dist < best) best = V[t].dist;
        }
        cout << best + 1 << endl;
    }

    return 0;
}

/*
2
3 4 0
####
###S
####

2
3 4 0
####
#..S
####

6
6 5 7
#####
#S..#
#@#.#
#...#
#@###
#.###
6 5 7
#####
#S..#
#@#..
#...#
#@###
#.###
4 5 3
#####
#S#.#
#@..#
###@#
3 3 50
@@@
@S@
@@@
3 3 0
@@@
@S@
@@@
3 4 0
####
#..S
####


 16, 5, 11, 52, 2, 1
 */