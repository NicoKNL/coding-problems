#include <iostream>
#include <vector>

using namespace std;

struct Node {
    vector<Node*> adj;
    bool visited = false;
    char state;
    bool is_target = false;
};

void oneRun()
{
    int n;
    cin >> n;
    Node nodes[n][n];
    vector<Node*> black; // queue
    vector<Node*> white; // queue
    int empty_cells = 0;

    // Fill the grid from console input
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> nodes[x][y].state;

            if (x == n-1 && nodes[x][y].state == 'W') nodes[x][y].is_target = true;
            if (y == n-1 && nodes[x][y].state == 'B') nodes[x][y].is_target = true;
            if (y == 0 && nodes[x][y].state == 'B') black.push_back(&nodes[x][y]);
            if (x == 0 && nodes[x][y].state == 'W') white.push_back(&nodes[x][y]);
            if (nodes[x][y].state == '.') empty_cells++;

            // Connect adjacent nodes
            if (y != 0)     nodes[x][y].adj.push_back(&nodes[x][y - 1]);
            if (y != n - 1) nodes[x][y].adj.push_back(&nodes[x][y + 1]);
            if (x != 0)     nodes[x][y].adj.push_back(&nodes[x - 1][y]);
            if (x != n - 1) nodes[x][y].adj.push_back(&nodes[x + 1][y]);
            if (y != n - 1 && x > 0) nodes[x][y].adj.push_back(&nodes[x - 1][y + 1]);
            if (y != 0 && x < n)     nodes[x][y].adj.push_back(&nodes[x + 1][y - 1]);
        }
    }

    /** Non recursive DFS for black */
    for (int i = 0; i < black.size(); i++) {
        Node* next = black.at(i);
        while (next) {
            (*next).visited = true;
            Node* new_next = nullptr;
            if ((*next).is_target) {
                cout << "Black wins" << endl;
                return;
            }
            for (auto adj : (*next).adj) {
                if ((*adj).state == 'B' && !(*adj).visited) {
                    if (new_next == nullptr) {
                        new_next = adj;
                    } else {
                        black.push_back(adj);
                    }
                }
            }
            next = new_next;
        }
    }

    /** Early out: if all cells are used, and black didn't win, then white won */
    if (empty_cells == 0) {
        cout << "White wins" << endl;
        return;
    }

    /** Non recursive DFS for white */
    for (int i = 0; i < white.size(); i++) {
        Node* next = white.at(i);
        while (next) {
            (*next).visited = true;
            Node* new_next = nullptr;
            if ((*next).is_target) {
                cout << "White wins" << endl;
                return;
            }
            for (auto adj : (*next).adj) {
                if ((*adj).state == 'W' && !(*adj).visited) {
                    if (new_next == nullptr) {
                        new_next = adj;
                    } else {
                        white.push_back(adj);
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
3
7
.WBW...
.BW.WW.
.BBWBB.
..BBWB.
..BWBW.
..BWB..
.WWWB..
5
..B..
.BBWB
WWWBW
B.WWB
.B...
4
BBWB
WWB.
BWWB
BWBW


2
4
BBWB
WWBB
BWWB
BWBW
4
BBWB
WWBW
BWWB
BWBW



1
3
...
...
.B.
 */