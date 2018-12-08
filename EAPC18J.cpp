#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

struct Node; // Predefinition

struct Edge {
    Node* source;
    Node* target;
    int weight;
    Edge(){};
    Edge(Node* s, Node* t, int w) {
        source = s;
        target = t;
        weight = w;
    }

    bool operator<(const Edge& other) const {
        return (weight > other.weight); // Watch out! Dirty priority queue hack :-) as it uses std::less as default comparison
    }
};

struct Node {
    int index;
    string chars;
    vector<Edge> edges;
    bool in_tree = false;
};

void oneRun()
{
    int n, length;
    cin >> n >> length;
    Node nodes[n];

    // Read in all character sequences into the nodes.
    for (int i = 0; i < n; i++) {
        cin >> nodes[i].chars;
        nodes[i].index = i;
    }

    // Construct the fully connected graph including all edge weights
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue; // Don't compare and connect from node X to node X

            int diff = 0;
            for (int k = 0; k < length; k++) {
                if (nodes[i].chars.at(k) != nodes[j].chars.at(k)) diff++;
            }
            nodes[i].edges.push_back(Edge(&nodes[i], &nodes[j], diff));
        }
    }

    // Construct the MST
    vector<pair<int, int>> connect;
    int cost = 0;
    priority_queue<Edge> e_queue;
    nodes[0].in_tree = true;
    for (auto edge: nodes[0].edges) {
        e_queue.push(edge);
    }

    Edge e;
    while(not e_queue.empty()) {
        // Pick and consume shortest edge in queue
        e = e_queue.top();
        e_queue.pop();

        if (not e.target->in_tree) {
            if (e.source->index > e.target->index) {
                pair<int, int> ab (e.target->index, e.source->index);   // Register edge in MST
                connect.push_back(ab);
            } else {
                pair<int, int> ab (e.source->index, e.target->index);   // Register edge in MST
                connect.push_back(ab);
            }

            cost += e.weight;           // Add the length of the edge to the cost sum
            e.target->in_tree = true;   // Mark the target node of the edge as being in the MST

            for (auto edge: e.target->edges) {  // Update the queue with the newly reachable edges
                e_queue.push(edge);
            }
        }
    }

    /** Finally return the answer */
    cout << cost << endl;
    for (auto c : connect) {
        cout << get<0>(c) << " " << get<1>(c) << endl;
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
input:
1
4 2
AA
AT
TT
TC

output:
3
0 1
1 2
2 3

input:
1
4 1
A
A
G
T

output:
2
0 1
0 2
0 3



input:
1
5 6
GAACAG
AAAAAA
AACATA
GAAAAG
ATAAAT

output:
7
0 3
1 2
1 3
1 4

input:
1
3 1
A
A
A


 */