#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <string>

using namespace std;

struct Node; // Predefinition

struct Edge {
    Edge(){}
    Edge(Node* t) {
        target = t;
    }

    Node* target;
    int capacity = 1;
    int flow;   // residual capacity can be derived from flow and capacity
    Edge* back; // Needed to update flow in reverse direction
};

struct Node {
    int x;
    int y;
    string word;
    vector<Edge*> adj;
    bool visited;
    Edge parent; // Reference to edge to parent to update flow
    int flow;    // Only for Edmonds-Karp
};

void oneRun()
{
    int h, v; // Number of horizontal, and vertical words
    cin >> h >> v;
    Node horizontal[h];
    Node vertical[v];

    Node source;
    Node sink;

    /** Read in all horizontal words and connect edges:
     *      from source to horizontal
     */
    for (int i = 0; i < h; i++) {
        cin >> horizontal[i].x;
        cin >> horizontal[i].y;
        cin >> horizontal[i].word;
        Edge from_source(&horizontal[i]);
        source.adj.push_back(&from_source);
    }

    /** Read in all vertical words and connect edges:
     *      from horizontal to vertical
     *      from vertical to sink
     */
    for (int i = 0; i < v; i++) {
        cin >> vertical[i].x;
        cin >> vertical[i].y;
        cin >> vertical[i].word;
        int min_y = vertical[i].y;
        int max_y = vertical[i].y + vertical[i].word.length();

        for (auto h: horizontal) {
            int min_x = h.x;
            int max_x = h.x + h.word.size();

            // Check if the words cross with each other
            if (min_y <= h.y && h.y <= max_y && min_x <= vertical[i].x && vertical[i].x <= max_x) {
                Edge intersection(&vertical[i]);
                h.adj.push_back(&intersection);
            }
        }

        Edge to_sink(&sink);
        vertical[i].adj.push_back(&to_sink);
    }
    
    int i = 0;
    i = 1;
    i++;





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