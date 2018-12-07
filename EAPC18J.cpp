#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Node; // Predefinition

struct Edge {
    Node* target;
    int weight;

    bool operator<(const Edge& rhs) const
    {
        return weight < rhs.weight;
    }
};

struct Node {
    string chars;
    vector<Edge*> edges;
    bool in_tree;
};

void oneRun()
{
    int n, length;
    cin >> n >> length;
    Node nodes[n];

    // Read in all character sequences into the nodes.
    for (int i = 0; i < n; i++) {
        cin >> nodes[i].chars;
    }

    // Construct the fully connected graph including all edge weights
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue; // Don't compare and connect from node X to node X

            int diff = 0;
            for (int k = 0; k < length; k++) {
                if (nodes[i].chars.at(k) != nodes[j].chars.at(k)) diff++;
            }
            Edge i2j; // i to j
            i2j.target = &nodes[i];
            i2j.weight = diff;
        }
    }

    queue<Edge*> queue1;
    queue1.
    vector<Node*> queue {&nodes[0]};
    Node* next;
    for (int i = 0; i < queue.size(); i++) {
        next = queue.at(i);
        next->in_tree = true;
        Edge* best_edge;
        for (auto edge: next->edges) {
            if (not edge->target->in_tree) {
                if (not best_edge or edge->weight < best_edge->weight) best_edge = edge;
            }
        }
        queue.push_back(best_edge->target);
    }

    /** set output to 2 decimals and pipe into cout */
    cout << expected_cost << endl;
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
3 6
##s###
#....#
#t####

output: 5.00

1
5 5
#s###
#...#
#.###
#...#
#t###

output: 8.00


1
3 7
#######
s.....t
#######

output: 6.00

1
6 3
#s#
#.#
#.#
#.#
#.#
#t#

output: 5.00

1
4 7
###s###
#.....#
#.#.#.#
###t###

output: 7.00

1
4 11
###########
#...#...###
s.#...#...#
#########t#

output: 14.00

1
4 11
###########
#...#...#.#
s.#...#...#
#########t#

output: 15.00

1
4 12
############
#...#...#..#
s.#...#...##
#########t##

output: 16.00

 */