#include <bits/stdc++.h>
#define MAX 5

using namespace std;

int V = 5;
long W[MAX][MAX]; // edge length between i and j
long D[MAX][MAX]; // distance between i and j
int P[MAX][MAX]; // path: i -> ... -> P[i][j] -> j
void FloydWarshall() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            D[i][j] = W[i][j];
            P[i][j] = i;
        }
    }

    // From i to i = 0
    for (int i = 0; i < V; i++) D[i][i] = 0;

    // Compute all pairs shortest paths
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = P[k][j];
                }
            }
        }
    }
}

vector<int> path;
void shortestPath(int s, int t) {
    if (s != t) shortestPath(s, P[s][t]);
    path.push_back(t);
}

int main() {
    // Initialize distances
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            W[i][j] = INT_MAX;
        }
    }

    W[0][1] = W[1][0] = 1;
    W[1][2] = W[2][1] = 12;
    W[2][4] = W[4][2] = 1;
    W[1][3] = W[3][1] = 1;
    W[3][4] = W[4][3] = 122;
    FloydWarshall();
    shortestPath(0, 4);
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
    cout << "success" << endl;
    return 0;
}