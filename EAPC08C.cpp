#include <iostream>
#include <vector>

using namespace std;

struct Node {
    vector<Node*> adj;
    bool visited = false;
    char state;
    int dist = -1;
    int choices = 0;
};

void oneRun()
{
    int height, width;
    cin >> height >> width;
    Node nodes[width][height];
    Node* target;

    // Fill the grid from console input
    char state;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            cin >> state;
            nodes[x][y].state = state;

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

    /** Non recursive DFS (backwards) from target to source */
    double sum = 0;
    (*target).dist = 0;
    vector<Node*> queue {target};

    for (int i = 0; i < queue.size(); i++) {
        Node *next = queue.at(i);
        while (next) {
            (*next).visited = true;
            Node *new_next = nullptr;
            char state;
            for (auto adj : (*next).adj) {
                state = (*adj).state;
                if ((state == '.' || state == 's' ) && !(*adj).visited) {
                    (*next).choices++;
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
    /** If we haven't returned yet, then the game is undecided */
    cout << "Not finished" << endl;
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
 */