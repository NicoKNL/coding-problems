#include <bits/stdc++.h>
using namespace std;

class Tile 
{
public:
    int m_id;
    vector<vector<char>> m_data;
    string top;
    string bottom;
    string right;
    string left;
    vector<string> edges;
    int count = 0;
    bool taken = false;

    Tile(int id, vector<vector<char>> tile_data)
    {
        m_id = id;
        m_data = tile_data;  
        findEdges();
    }

    void rotateLeft()
    {
        vector<vector<char>> new_grid = m_data;
        int w = m_data.size();
        for (int r = 0; r < w; ++r) {
            for (int c = 0; c < w; ++c) {
                new_grid[w - c - 1][r] = m_data[r][c];
            }
        }
        m_data = new_grid;
        findEdges();
    }

    void flip()
    {
        vector<vector<char>> new_grid = m_data;
        int w = m_data.size();
        for (int r = 0; r < w; ++r) {
            for (int c = 0; c < w; ++c) {
                new_grid[r][w - c - 1] = m_data[r][c];
            }
        }
        m_data = new_grid;
        findEdges();
    }

    void findEdges()
    {
        top = "";
        bottom = "";
        right = "";
        left = "";
        for (int i = 0; i < m_data.size(); ++i) {
            top += m_data[0][i];
            bottom += m_data[m_data.size() - 1][i];
            right += m_data[i][m_data.size() - 1];
            left += m_data[i][0];
        }
        reverse(bottom.begin(), bottom.end());
        reverse(left.begin(), left.end());
        edges = {top, right, bottom, left};
    }

    vector<string> getEdges()
    {
        return edges;
    }
};

vector<Tile> tiles;

int main() 
{
    // grab input file
    ifstream infile ("../advent-of-code-2020/input/20.txt");
    if (!infile.is_open()) {
        return -1;
    }

    string line = "";
    int tile_id;
    vector<vector<char>> tile;
    bool first = true;
    while (getline(infile, line)) {
        if (line[0] == 'T' && !first) {
            tiles.push_back(Tile(tile_id, tile));
            tile_id = stoi(line.substr(5, 4));
            tile = vector<vector<char>>();
        } else if (line[0] == 'T') {
            first = false;
            tile_id = stoi(line.substr(5, 4));
        } else if (line[0] == '.' || line[0] == '#') {
            vector<char> row;
            for (char c : line) {
                if (c == '.' || c == '#') row.emplace_back(c);
            }
            tile.emplace_back(row);
        }
    }
    tiles.push_back(Tile(tile_id, tile));

    vector<string> edges;
    vector<string> matched_edges;
    for (Tile tile_a : tiles) {
        for (string edge : tile_a.getEdges()) {
            edges.emplace_back(edge);
        }
    }

    for (int i = 0; i < edges.size(); ++i) {
        string edge_a = edges[i];
        for (int j = 0; j < edges.size(); ++j) {
            if (i == j) continue;
            string edge_b = edges[j];
            string edge_b_rev = edge_b;
            reverse(edge_b_rev.begin(), edge_b_rev.end());

            if (edge_a == edge_b || edge_a == edge_b_rev) {
                for (Tile & tile : tiles) { // Find all tiles with this edge
                    for (string t_edge : tile.getEdges()) {
                        if (t_edge == edge_b || t_edge == edge_b_rev) {
                            matched_edges.push_back(edge_a);
                            ++tile.count;
                        }
                    }
                }                
            }
        }
    }

    for (Tile tile : tiles) {
        if (tile.count / 2 == 2) {
            cout << tile.m_id << endl;
            // 2521
            // 2633
            // 3067
            // 1061
        }
    }

    // Place first
    vector<vector<Tile>> grid;
    for (Tile & tile : tiles) {
        if (tile.m_id == 2521) {
            tile.taken = true;
            grid.push_back({tile});
        }
    }

    // Rotate first
    int i = 0;
    while (true) {
        bool right = false;
        bool bottom = false;
        for (string edge : matched_edges) {
            string r_edge = edge;
            reverse(r_edge.begin(), r_edge.end());
            if (edge == grid[0][0].right) right = true;
            if (edge == grid[0][0].bottom) bottom = true;
        }

        if (right && bottom) {
            cout << "found" << endl;
            break;
        } else {
            if (i == 4) grid[0][0].flip();
            grid[0][0].rotateLeft();
        }
        ++i;
    }

    // Complete first row 
    string right = grid[0][0].right;
    bool found = true;
    while (found) {
        found = false;
        for (Tile & tile : tiles) {
            if (tile.taken) continue;
            for (int j = 0; j < 4 && !found; ++j) {
                tile.rotateLeft();
                if (tile.left == right) {
                    found = true;
                    right = tile.right;
                    tile.taken = true;
                    grid[0].push_back(tile);
                } 
            }
            if (found) continue;
            tile.flip();
            for (int j = 0; j < 4 && !found; ++j) {
                tile.rotateLeft();
                if (tile.left == right) {
                    found = true;
                    right = tile.right;
                    tile.taken = true;
                    grid[0].push_back(tile);
                } 
            }

            if (found) break;
        }
    }
    cout << "tiles: " << tiles.size() << endl;
    cout << "first row: " << grid[0].size() << endl;

    for (int r = 1; r < 12; ++r) {
        cout << "starting: " << r << endl;
        string bottom = grid[r - 1][0].bottom;
        // Place first of new row
        found = false;
        for (Tile & tile : tiles) {
            if (found) break;
            if (tile.taken) continue;
            for (int j = 0; j < 4 && !found; ++j) {
                tile.rotateLeft();
                if (tile.top == bottom) {
                    found = true;
                    right = tile.right;
                    tile.taken = true;
                    grid.push_back({tile});
                } 
            }
            if (found) continue;
            tile.flip();

            for (int j = 0; j < 4 && !found; ++j) {
                tile.rotateLeft();
                if (tile.top == bottom) {
                    found = true;
                    right = tile.right;
                    tile.taken = true;
                    grid.push_back({tile});
                } 
            }
        }

        cout << "first found" << endl;

        // Complete row 
        right = grid[r][0].right;
        found = true;
        while (found) {
            cout << "add..." << endl;
            found = false;
            for (Tile & tile : tiles) {
                if (tile.taken) continue;
                for (int j = 0; j < 4 && !found; ++j) {
                    tile.rotateLeft();
                    if (tile.left == right) {
                        found = true;
                        right = tile.right;
                        tile.taken = true;
                        grid[r].push_back(tile);
                    } 
                }
                
                if (found) continue;
                tile.flip();
                for (int j = 0; j < 4 && !found; ++j) {
                    tile.rotateLeft();
                    if (tile.left == right) {
                        found = true;
                        right = tile.right;
                        tile.taken = true;
                        grid[r].push_back(tile);
                    } 
                }

                if (found) break;
            }
        }
    }

    cout << grid.size() << " " << grid[0].size() << endl;

    // construct final grid
    vector<vector<char>> image;
    for (int r = 0; r < grid.size(); ++r) {
        cout << "r: " << r << " " << "max c: " << grid[r].size() << endl;
        for (int j = 0; j < grid[0][0].m_data.size(); ++j) {
            image.push_back({});
        }
        for (int c = 0; c < grid[r].size(); ++c) {
            for (int ir = 0; ir < grid[r][c].m_data.size(); ++ir) {
                // image[r + ir].insert(image[r + ir].end(), grid[r][c].m_data.begin(), grid[r][c].m_data.end());
            }
        }
    }

    cout << image.size() << "x" << image[0].size() << endl;
}
