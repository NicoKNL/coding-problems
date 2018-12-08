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
        return (weight > other.weight); // Watch out! Dirty hack :-)
    }
};

struct Node {
    int index;
    string chars;
    vector<Edge> edges;
    bool in_tree = false;
};

template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top().weight << " ";
        q.pop();
    }
    std::cout << '\n';
}

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
    vector<Node*> v_queue {&nodes[0]};
    Node* next;
    for (int i = 0; i < v_queue.size(); i++) {
        next = v_queue.at(i);
        next->in_tree = true;
        for (auto edge: next->edges) {
            e_queue.push(edge);
        }
    }

    Edge best_edge;
    while(not e_queue.empty()) {
        best_edge = e_queue.top();
        e_queue.pop();

        if (not best_edge.target->in_tree) {
            pair<int, int> ab (best_edge.source->index, best_edge.target->index);
            cost += best_edge.weight;
            connect.push_back(ab);
            v_queue.push_back(best_edge.target);
            for (auto edge: best_edge.target->edges) {
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
 */