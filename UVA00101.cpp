#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

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
        move = false; // Assume piling
        onto = false; // Assume over
        if (s == "quit") break;

        if (s == "move") move = true;
        cin >> source >> s >> target;



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