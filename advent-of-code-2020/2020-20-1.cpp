#include <bits/stdc++.h>
using namespace std;

class Tile 
{
private:
    int m_id;
    vector<vector<char>> m_data;
    vector<string> edges;
    vector<Tile> adj;

    void findEdges()
    {
        string top;
        string bottom;
        string right;
        string left;
        for (int i = 0; i < m_data.size(); ++i) {
            top += m_data[0][i];
            bottom += m_data[m_data.size() - 1][i];
            right += m_data[i][m_data.size() - 1];
            left += m_data[i][0];
        }
        // reverse(bottom.begin(), bottom.end());
        // reverse(left.begin(), left.end());
        edges.emplace_back(top);
        edges.emplace_back(right);
        edges.emplace_back(bottom);
        edges.emplace_back(left);
    }
public:
    int count = 0;
    Tile(int id, vector<vector<char>> tile_data)
    {
        m_id = id;
        m_data = tile_data;  
        findEdges();
    }

    vector<string> & getEdges()
    {
        return edges;
    }

    int getId()
    {
        return m_id;
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
    for (Tile tile_a : tiles) {
        cout << tile_a.getId() << endl;
        for (string edge : tile_a.getEdges()) {
            edges.emplace_back(edge);
        }
    }

    cout << edges.size() << endl;
    sort(edges.begin(), edges.end());
    cout << edges.size() << endl;

    for (int i = 0; i < edges.size(); ++i) {
        cout << "edge: " << edges[i] << endl;
    }

    cout << "Starting matching" << endl;
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
                            ++tile.count;
                        }
                    }
                }                
            }
        }
    }

    cout << "Starting count" << endl;
    uint64_t result = 1;
    for (Tile tile : tiles) {
        if (tile.count / 2 == 2) {
            result *= (uint64_t) tile.getId(); 
            cout << tile.getId() << endl;
        }
    }
    cout << result << endl;
}
