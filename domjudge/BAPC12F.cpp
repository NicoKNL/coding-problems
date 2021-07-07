#include <iostream>
#include <vector>

using namespace std;

struct Node {
    vector<Node*> adj;
    int dist = 0;
    char state;
    bool on_fire = false;
    int fire_time = 0;
};

void oneRun()
{
    // Construct the grid according to input (+2 for boundaries)
    int width, height;
    cin >> width >> height;
    Node nodes[width+2][height+2];  // Storing the nodes
    vector<Node*> fire;             // Storing references to the nodes where the fire is
    Node* root;                     // For storing the starting point

    // Fill the grid from console input
    for (int y = 0; y < height + 2; y++) {
        for (int x = 0; x < width + 2; x++) {
            if (y == 0 || y == height + 1 || x == 0 || x == width + 1) {
                nodes[x][y].state = 'F'; // F for FREEDOM!
            } else {  // Else fill in the input
                cin >> nodes[x][y].state;
                if (nodes[x][y].state == '@') root = &nodes[x][y];
                if (nodes[x][y].state == '*') {
                    nodes[x][y].on_fire = true;
                    fire.push_back(&nodes[x][y]);
                }
            }
            // Connect adjacent nodes
            if (y != 0)          nodes[x][y].adj.push_back(&nodes[x][y - 1]);
            if (y != height + 1) nodes[x][y].adj.push_back(&nodes[x][y + 1]);
            if (x != 0)          nodes[x][y].adj.push_back(&nodes[x - 1][y]);
            if (x != width + 1)  nodes[x][y].adj.push_back(&nodes[x + 1][y]);
        }
    }

    /** Spreading the fire
     *  Calculating the time it takes for a cell to become burning */
    bool done_spreading = false;
    int time = 1;
    while (not done_spreading) {
        // Step for the fire
        vector<Node*> new_fire;
        for (auto f: fire) {
            for (auto neighbour: (*f).adj) {
                if (!(*neighbour).on_fire && (*neighbour).state != '#' && (*neighbour).state != 'F') {
                    (*neighbour).on_fire = true;
                    (*neighbour).fire_time = time;
                    new_fire.push_back(neighbour);
                }
            }
        }
        if (not new_fire.size()) done_spreading = true;
        fire = new_fire;
        time++;
    }

    /** BFS */
    vector<Node*> queue {root};
    for (int i = 0; i < queue.size(); i++) {
        Node* node = queue.at(i);
        for (auto neighbour: (*node).adj) {
            if ((*neighbour).dist > 0 || ((*neighbour).state != '.' && (*neighbour).state != 'F')) continue; // node already found

            (*neighbour).dist = (*node).dist + 1;
            if ((*neighbour).dist < (*neighbour).fire_time || !(*neighbour).on_fire) {
                queue.push_back(neighbour);
            }

            if ((*neighbour).state == 'F') {
                cout << (*neighbour).dist << endl;
                return;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

int main()
{
    int n_cases;
    cin >> n_cases;
    while (n_cases--) oneRun();
    return 0;
}

/** Test cases
5
4 3
####
#*@.
####
7 6
###.###
#*#.#*#
#.....#
#.....#
#..@..#
#######
7 4
###.###
#....*#
#@....#
.######
5 5
.....
.***.
.*@*.
.***.
.....
3 3
###
#@#
###


1
6 5
******
######
#@....
######
******

 */