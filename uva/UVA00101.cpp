#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

pair<int, int> find(int n, const vvi & blocks) {
    for (int r = 0; r < blocks.size(); r++) {
        for (int c = 0; c < blocks[r].size(); c++) {
            if (blocks[r][c] == n) {
                return {r, c};
            }
        }
    }
    return {-1, -1};
}

void return_above(int r, int c, vvi & blocks) {
    for (int i = blocks[r].size() - 1; i > c; i--) {
        int target = blocks[r][i];
        blocks[target].push_back(blocks[r][i]);
        blocks[r].pop_back();
    }
}

void pile(int r, int c, int tr, vvi & blocks) {
    vi astack;
    for (int i = c; i < blocks[r].size(); i++) {
        astack.push_back(blocks[r][i]);
    }
    blocks[r].erase(blocks[r].begin() + c, blocks[r].end());
    for (int i = 0; i < astack.size(); i++) {
        blocks[tr].push_back(astack[i]);
    }
}

int main() {
    int n, source, target;
    string s;
    bool move, onto;
    cin >> n;

    vvi blocks;
    vi block_row;
    // Initialize the array
    for (int i = 0; i < n; i++) {
        block_row.clear();
        block_row.push_back(i);
        blocks.push_back(block_row);
    }

    while (true) {
        cin >> s;
        if (s == "quit") break;

        int a, b;
        string cmd;
        cin >> a >> cmd >> b;
        pair<int, int> pos_a = find(a, blocks);
        pair<int, int> pos_b = find(b, blocks);

        if (a == b || pos_a.first == pos_b.first) {
            continue;
        }
        if (s == "move" && cmd == "onto") {
            return_above(pos_a.first, pos_a.second, blocks);
            blocks[pos_a.first].pop_back(); // remove a
            return_above(pos_b.first, pos_b.second, blocks);
            blocks[pos_b.first].push_back(a);
        } else if (s == "move" && cmd == "over") {
            return_above(pos_a.first, pos_a.second, blocks);
            blocks[pos_a.first].pop_back(); // remove a
            blocks[pos_b.first].push_back(a);
        } else if (s == "pile" && cmd == "onto") {
            return_above(pos_b.first, pos_b.second, blocks);
            pile(pos_a.first, pos_a.second, pos_b.first, blocks);
        } else if (s == "pile" && cmd == "over") {
            pile(pos_a.first, pos_a.second, pos_b.first, blocks);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << i << ":";
        for (int j = 0; j < blocks.at(i).size(); j++) {
            if (j == 0) cout << " ";
            cout << blocks.at(i).at(j);
            if (j < blocks.at(i).size() - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}