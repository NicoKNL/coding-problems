#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    vector<Node*> adj;
    bool visited = false;
    char state;
};

void oneRun()
{
    int honey;
    cin >> honey;
    int width, height;
    cin >> height >> width;
    Node nodes[width][height];
    vector<Node*> empty_cells; // queue for possible starting points

    // Fill the grid from console input
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            cin >> nodes[x][y].state;

            if (nodes[x][y].state == '.') empty_cells.push_back(&nodes[x][y]);

            // Connect adjacent nodes
            if (y != 0)     nodes[x][y].adj.push_back(&nodes[x][y - 1]);
            if (y != height - 1) nodes[x][y].adj.push_back(&nodes[x][y + 1]);
            if (x != 0)     nodes[x][y].adj.push_back(&nodes[x - 1][y]);
            if (x != width - 1) nodes[x][y].adj.push_back(&nodes[x + 1][y]);

            if (y % 2 == 0) {
                if (x > 0) {
                    if (y > 0)      nodes[x][y].adj.push_back(&nodes[x - 1][y - 1]);
                    if (y < height - 1)  nodes[x][y].adj.push_back(&nodes[x - 1][y + 1]);
                }
            } else {
                if (x < width - 1) {
                    if (y > 0)      nodes[x][y].adj.push_back(&nodes[x + 1][y - 1]);
                    if (y < height - 1)  nodes[x][y].adj.push_back(&nodes[x + 1][y + 1]);
                }
            }
        }
    }

    int disconnected_parts = 0;
    vector<int> sizes;
    for (int i = 0; i < empty_cells.size(); i++) {
        Node* next = empty_cells.at(i);

        if (next -> visited) continue;
        next->visited = true;

        int size = 0;
        disconnected_parts++;

        vector<Node*> bfs_queue = {empty_cells.at(i)};
        for (int j = 0; j < bfs_queue.size(); j++) {
            next = bfs_queue.at(j);
            size++;
            for (auto adj: next->adj) {
                if (adj->visited || adj->state == '#') continue;
                adj->visited = true;
                bfs_queue.push_back(adj);
            }
        }
        sizes.push_back(size);
    }


    sort(sizes.begin(), sizes.end(), greater<int>());

    int i = 0;
    while (honey > 0) {
        honey -= sizes.at(i);
        i++;
    }
    /** If we haven't returned yet, then the game is undecided */
    cout << i << endl;
}

int main()
{
    oneRun();
    return 0;
}

/** Test cases

8 4 4
. # # .
 # . # .
# # # .
 # . . .

1
6 3 6
. . # # . .
 . . # # . #
# # # . # #


1
7 3 7
# . # . # . #
 # . # . # . #
# . # . # . #


1
7 4 4
. # . #
 # . # .
# . # .
 . # . #

1
8 4 4
# . # .
 . # . #
. # . #
 # . # .

1
9 3 3
. . .
 . . .
. . .


1
2 3 3
. # .
 # # #
. . .

1 5 1
#
 .
#
 .
#

1 1 5
# . # . #
 */