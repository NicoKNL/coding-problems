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



}

int main()
{
    int n_cases;
    cin >> n_cases;
    while (n_cases--) oneRun();
    return 0;
}

/** Test cases

 */