#include <iostream>
#include <vector>

using namespace std;

struct Node {
    Node* parent = nullptr;
    vector<Node*> adj;
    vector<Node*> children;
    bool visited = false;
    char state;
    int size;
    int dist = -1;
    int x;
    int y;
};

int calculateTreeProperties(Node* tree)
{
    int subtree_size = 1;
    for (auto child : (*tree).children) {
        subtree_size += calculateTreeProperties(child);
    }
    (*tree).size = subtree_size;
    return subtree_size;
}

void oneRun()
{
    int height, width;
    cin >> height >> width;
    Node nodes[width][height];
    Node* root;
    Node* target;

    // Fill the grid from console input
    char state;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            cin >> state;
            nodes[x][y].state = state;
            nodes[x][y].x = x;
            nodes[x][y].y = y;
            if (state == 's') root = &nodes[x][y];
            if (state == 't') target = &nodes[x][y];

            if (state == '.' || state == 's' || state == 't') {
                // Connect adjacent nodes
                if (y != 0)     nodes[x][y].adj.push_back(&nodes[x][y - 1]);
                if (y != height - 1) nodes[x][y].adj.push_back(&nodes[x][y + 1]);
                if (x != 0)     nodes[x][y].adj.push_back(&nodes[x - 1][y]);
                if (x != width - 1) nodes[x][y].adj.push_back(&nodes[x + 1][y]);
            }
        }
    }

//    /** Print the array */
//    for (int y = 0; y < height; y++) {
//        for (int x = 0; x < width; x++) {
//            cout << nodes[x][y].state;
//        }
//        cout << endl;
//    }

    /** Non recursive DFS from source to construct the TREE */
    vector<Node*> queue {root};

    for (int i = 0; i < queue.size(); i++) {
        Node* next = queue.at(i);
        while (next) {
            (*next).visited = true;
            Node *new_next = nullptr;
            char state;
            for (auto adj : (*next).adj) {
                state = (*adj).state;
                if ((state == '.' || state == 't' ) && !(*adj).visited) {
                    (*adj).parent = next;           // Store parent
                    (*next).children.push_back(adj);// Store child
                    if (new_next == nullptr) {
                        new_next = adj;
                    } else {
                        queue.push_back(adj);
                    }
                }
            }
            next = new_next;
        }
    }

    /** Calculate subtree sizes */
    calculateTreeProperties(root);

    /** Traverse from target up the tree to the source */
    double expected_cost = 0.00;
    int steps = 0; // To track steps between 'intersections' in the graph
    Node* next = target;
    Node* parent = (*next).parent;
    while (next != root) {
        steps++;
        int child_count = (*parent).children.size();
        if (child_count > 1) {
            for (auto child : (*parent).children) {
                if (child == next) {
                    expected_cost += steps;
                } else {
                    expected_cost += child->size;
                }
            }
            steps = 0; // Reset steps to track them until next intersection
        }
        next = parent;
        parent = (*next).parent;
    }
    expected_cost += steps;// + 1.0; // Also add the final step to the entrance

    /** set output to 2 decimals and pipe into cout */
    cout.precision(2);
    cout << fixed << expected_cost << endl;
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

output: 9.00

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