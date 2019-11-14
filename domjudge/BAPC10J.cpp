#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int MAX_V = 1010;
vvi residual;
int max_flow, flow, s, t;
vi parent;

struct Word {
    int i; // id
    int x;
    int y;
    string w; // word
};

// assumes s, t, and residual are initialized
void read_graph(int h, int v) {
    vector<Word> h_words;
    vector<Word> v_words;

    int x, y;
    string w;

    // read in horizontal words
    for (int i = 0; i < h; i++) {
        cin >> x >> y >> w;
        h_words.push_back({i, x, y, w});
        residual[i][t] = 1; // h-word to sink
    }

    // read in vertical words
    for (int i = h; i < h + v; i++) {
        cin >> x >> y >> w;
        v_words.push_back({i, x, y, w});
        residual[s][i] = 1; // source to v-word
    }

    // set up bipartite edges. Going from vertical words to horizontal words, capacity = 1;
    for (Word h_word : h_words) {
        for (Word v_word : v_words) {
            if (h_word.x <= v_word.x && v_word.x <= h_word.x + h_word.w.size() - 1) {
                if (v_word.y <= h_word.y && h_word.y <= v_word.y + v_word.w.size() - 1) {
                    // Then they intersect at (v_word.x, h_word.y)
                    char a = h_word.w[v_word.x - h_word.x];
                    char b = v_word.w[h_word.y - v_word.y];
//                    printf("[%s] [%s] [%c] [%c]\n", h_word.w.c_str(), v_word.w.c_str(), a, b);
                    if (a != b) {
                        residual[v_word.i][h_word.i] = 1;
                    }
                }
            }
        }
    }
}

void augment(int v, int min_edge) {
    if (v == s) {
        flow = min_edge;
        return;
    } else if (parent[v] != -1) {
        augment(parent[v], min(min_edge, residual[parent[v]][v]));
        residual[parent[v]][v] -= flow;
        residual[v][parent[v]] += flow;
    }
}

int main()
{
    int n_cases;
    cin >> n_cases;
    while (n_cases--) {
        int h, v; // Number of horizontal, and vertical words
        cin >> h >> v;

        residual = vector<vector<int>> (MAX_V, vector<int>(MAX_V));
        s = h + v;
        t = h + v + 1;

        read_graph(h, v); // construct initial capacity values etc

        max_flow = 0;
        while (true) {
            flow = 0;
            vi dist(MAX_V, INT_MAX); dist[s] = 0;
            queue<int> Q; Q.push(s);
            parent.assign(MAX_V, -1);
            while (!Q.empty()) {
                int u = Q.front(); Q.pop();
                if (u == t) break; // reached sink
                for (int v = 0; v < MAX_V; v++) {
                    if (residual[u][v] > 0 && dist[v] == INT_MAX) {
                        dist[v] = dist[u] + 1;
                        Q.push(v);
                        parent[v] = u;
                    }
                }
            }
            augment(t, INT_MAX);
            if (flow == 0) break;
            max_flow += flow;
        }
        printf("%d\n", h + v - max_flow);
    }
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